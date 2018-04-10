#include "GameManager.h"

#include "Common.h"
#include "Game.h"
#include "IPlayer.h"
#include "ImportExportUtils.h"

namespace 
{
    const size_t g_max_move_number = 300;
}

namespace Chess
{
    GameManager::EGameResult GameManager::PerformGame(
        IPlayer& i_player_white, IPlayer& i_player_black,
        GameManager::TOptionalStream i_log_summary, 
        GameManager::TOptionalStream i_log_verbose)
    {
        Chess::Game game;

        auto get_current_player = [&](EColor i_color) -> IPlayer&
        {
            if (i_color == EColor::White)
                return i_player_white;
            else
                return i_player_black;
        };

        bool end_game = false;

        do
        {
            bool success;
            do
            {
                auto& current_player = get_current_player(game.GetColorToMove());
                const auto move = current_player.GetMove(game.GetBoard());
                
                if (i_log_verbose)
                {
                    i_log_verbose->get() 
                        << IO::StateToFENString(game.GetBoard().GetState()) << '\n'
                        << PositionToString(move.m_from) << ' ' << PositionToString(move.m_to) << '\n';
                }
                
                success = game.MakeMoveIfAllowed(move);
                if (!success && i_log_summary)
                {
                    i_log_summary->get() << "Incorrect move" << std::endl;
                    const auto position_fen_str = IO::StateToFENString(game.GetBoard().GetState());
                    const auto move_str = PositionToString(move.m_from) + " " + PositionToString(move.m_to);
                    i_log_summary->get() << "\n=====================\n" 
                              << "Position:\n" << position_fen_str
                              << "\nMove: " << move_str << "\n";
                }
            } while (!success);
            
            const auto possible_next_moves = GetPossibleMoves(game.GetBoard(), game.GetColorToMove());
            if (possible_next_moves.empty())
            {
                if (game.GetColorToMove() == EColor::White)
                {
                    if (i_log_summary)
                        i_log_summary->get() << "\n\n" << game.GetBoard().ToString();   
                    return EGameResult::BlackWin;
                }
                else
                {
                    if (i_log_summary)
                        i_log_summary->get() << "\n\n" << game.GetBoard().ToString();
                    return EGameResult::WhiteWin;
                }
            }
            if (game.GetCurrentMoveNumber() >= g_max_move_number)
            {
                if (i_log_summary)
                    i_log_summary->get() << "\n\n" << game.GetBoard().ToString();
                return EGameResult::Draw;
            }
        } while (!end_game);
    }
}