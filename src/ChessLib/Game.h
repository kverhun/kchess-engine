#pragma once

#include "Board.h"

namespace Chess
{
    class Game
    {
    public:
        Game() = default;
    private:
        Board m_board;
    };
}