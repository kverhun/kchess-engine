#pragma once

#include "Piece.h"

#include <map>

namespace Chess
{
    class Board
    {
    public:
        Board();

        std::string ToString() const;
    private:
        std::map<TPosition, Piece> m_board_state;
    };
}