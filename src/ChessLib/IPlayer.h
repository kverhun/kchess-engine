#pragma once

#include "Board.h"
#include "Common.h"

namespace Chess
{
    class Board;

    class IPlayer
    {
    public:
        virtual ~IPlayer() {}

        virtual Move GetMove(const Board& i_board) = 0;
    };
}