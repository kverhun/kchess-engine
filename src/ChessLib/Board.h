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

        void MakeMove(const Move& i_move);

    private:
        std::map<TPosition, Piece> m_board_state;
    };
}