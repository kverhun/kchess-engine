#pragma once

#include "ChesslibAPI.h"
#include "Board.h"

namespace Chess
{
    class CHESSLIB_API Game
    {
    public:
        Game() = default;

    private:
        Board m_board;
    };
}