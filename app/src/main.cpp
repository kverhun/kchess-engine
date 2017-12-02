#include <iostream>
#include <map>
#include <string>

#include "Board.h"
#include "Piece.h"

int main(int i_argc, char** ip_argv)
{
    Chess::Board board{};
    std::cout << board.ToString();

    board.Move({'e',2}, {'e',4});
    std::cout << "\n\n" << board.ToString();
    return 0;
}