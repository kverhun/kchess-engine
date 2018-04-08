#include "GameManager.h"

#include "Common.h"
#include "Game.h"
#include "IPlayer.h"

#include <iostream>

namespace 
{
    const size_t g_max_move_number = 300;
}

namespace Chess
{
    GameManager::EGameResult GameManager::PerformGame(
        IPlayer& i_player_white, IPlayer& i_player_black)
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
                success = game.MakeMoveIfAllowed(move);
                if (!success)
                    std::cout << "Incorrect move" << std::endl;
            } while (!success);
            
            const auto possible_next_moves = GetPossibleMoves(game.GetBoard(), game.GetColorToMove());
            if (possible_next_moves.empty())
            {
                if (game.GetColorToMove() == EColor::White)
                {
                    std::cout << "\n\n" << game.GetBoard().ToString();   
                    return EGameResult::BlackWin;
                }
                else
                {
                    std::cout << "\n\n" << game.GetBoard().ToString();
                    return EGameResult::WhiteWin;
                }
            }
            if (game.GetCurrentMoveNumber() >= g_max_move_number)
            {
                std::cout << "\n\n" << game.GetBoard().ToString();
                return EGameResult::Draw;
            }
        } while (!end_game);
    }
}