#include <iostream>
#include <map>
#include <string>

#include "Board.h"
#include "Piece.h"

int main(int i_argc, char** ip_argv)
{
    Chess::Board board{};
    std::cout << board.ToString();

    board.Move(Chess::PositionFromString("e2"), Chess::PositionFromString("e4"));
    std::cout << "\n\n" << board.ToString();
    return 0;
}