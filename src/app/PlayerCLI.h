#pragma once

#include <ChessLib/IPlayer.h>

class PlayerCLI : public Chess::IPlayer
{
public:
    Chess::Move GetMove(const Chess::Board& i_board) override;
};