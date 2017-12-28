#include <iostream>
#include <map>
#include <string>

#include "CLI.h"
#include "PlayerCLI.h"

#include <ChessLib/Board.h>
#include <ChessLib/Piece.h>

int main(int i_argc, char** ip_argv)
{
    Chess::Board board{};
    std::cout << board.ToString();

    PlayerCLI player_white;
    PlayerCLI player_black;

    for (int i = 0; i < 5; ++i)
    {
        const auto move = i % 2 ? player_black.GetMove(board) : player_white.GetMove(board);
        board.MakeMove(move);

        std::cout << board.ToString() << '\n';
    }

    std::cout << "\n\n" << board.ToString();
    return 0;
}