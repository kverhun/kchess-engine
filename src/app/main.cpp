#include <iostream>
#include <map>
#include <string>

#include "CLI.h"
#include "PlayerCLI.h"

#include <ChessLib/Game.h>
#include <ChessLib/Piece.h>

int main(int i_argc, char** ip_argv)
{
	Chess::Game game;
    std::cout << game.GetBoard().ToString();

    PlayerCLI player_white;
    PlayerCLI player_black;

    for (int i = 0; i < 5; ++i)
    {
		bool success;
		do
		{
			const auto move = i % 2
				? player_black.GetMove(game.GetBoard())
				: player_white.GetMove(game.GetBoard());
			success = game.MakeMoveIfAllowed(move);
			if (!success)
				std::cout << "Incorrect move" << std::endl;
		} while (!success);
	    std::cout << "\n\n" << game.GetBoard().ToString();
    }

    return 0;
}