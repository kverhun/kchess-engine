#include "PlayerCLI.h"

#include "CLI.h"

Chess::Move PlayerCLI::GetMove(const Chess::Board& i_board)
{
    Chess::TPosition from, to;
    std::tie(from, to) = CLI::AskForMove();
    return {from, to};
}