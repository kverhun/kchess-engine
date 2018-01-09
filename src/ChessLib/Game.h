#pragma once

#include "ChesslibAPI.h"

#include "Board.h"

namespace Chess
{
    class CHESSLIB_API Game
    {
    public:
        Game() = default;
        
        bool MakeMoveIfAllowed(const Move& i_move);

    private:
        Board m_board;
    };
}