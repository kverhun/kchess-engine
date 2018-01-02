#pragma once

#include "Board.h"

namespace Chess
{
    class Game
    {
    public:
        Game() = default;
        
        bool MakeMoveIfAllowed(const Move& i_move);

    private:
        Board m_board;
    };
}