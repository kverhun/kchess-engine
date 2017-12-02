#include <iostream>
#include <map>
#include <string>

#include "Board.h"
#include "Piece.h"

int main(int i_argc, char** ip_argv)
{
    Chess::Board board{};
    std::cout << board.ToString();
    return 0;
}