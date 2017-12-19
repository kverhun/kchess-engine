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

        void Move(const TPosition& i_from, const TPosition& i_to);
    private:
        std::map<TPosition, Piece> m_board_state;
    };
}