#include <iostream>
#include <map>
#include <string>

#include "Board.h"
#include "CLI.h"

#include <ChessLib/Piece.h>

int main(int i_argc, char** ip_argv)
{
    Chess::Board board{};
    std::cout << board.ToString();

    for (int i = 0; i < 5; ++i)
    {
        Chess::TPosition from, to;
        std::tie(from, to) = CLI::AskForMove();
        board.Move(from, to);

        std::cout << board.ToString() << '\n';
    }

    std::cout << "\n\n" << board.ToString();
    return 0;
}