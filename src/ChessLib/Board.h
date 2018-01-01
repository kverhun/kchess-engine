#pragma once

#include "Piece.h"

#include <map>

namespace Chess
{
    class CHESSLIB_API Board
    {
    public:
        Board();
        Board(const Board&) = delete;
        Board& operator=(const Board&) = delete;

        std::string ToString() const;

        void MakeMove(const Move& i_move);

    private:
        std::map<TPosition, Piece> m_board_state;
    };
}