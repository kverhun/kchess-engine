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
        GameManager::TOptionalStream i_log_verbose,
        TOptionalGameInfo i_game_info)
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
        EGameResult game_result = [&]()
        {
            while(true)
            {
                bool success = true;
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
                        const auto position_fen_str = IO::StateToFENString(game.GetBoard().GetState());
                        const auto move_str = PositionToString(move.m_from) + " " + PositionToString(move.m_to);
                        i_log_summary->get() << "\n=====================\n" 
                                << "Incorrect move:\n"
                                << "Position:\n" << position_fen_str
                                << "\nMove: " << move_str << "\n";
                    }
                    if (success && i_game_info)
                    {
                        i_game_info->get().m_moves.push_back(move);
                        i_game_info->get().m_states.push_back(game.GetBoard().GetState());
                    }
                } while (!success);
                
                const auto possible_next_moves = GetPossibleMoves(game.GetBoard(), game.GetColorToMove());
                if (possible_next_moves.empty())
                {
                    if (game.GetColorToMove() == EColor::White)
                        return EGameResult::BlackWin;
                    else
                        return EGameResult::WhiteWin;
                }
                if (game.GetCurrentMoveNumber() >= g_max_move_number)
                    return EGameResult::Draw;
            }
            
        }();
        if (i_log_summary)
            i_log_summary->get() << "\n\n" << game.GetBoard().ToString();
        if (i_log_verbose)
        {
            i_log_verbose->get() << IO::StateToFENString(game.GetBoard().GetState()) << '\n';
            i_log_verbose->get() << "\n\n" << game.GetBoard().ToString();
        }
        if (i_game_info)
            i_game_info->get().m_result = game_result;
        return game_result;
    }
}