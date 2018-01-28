#pragma once

#include "ChesslibAPI.h"

#include <utility>

namespace Chess
{
    class Board;

    using TPosition = std::pair<short, short>;

    enum class EColor
    {
        White,
        Black
    };

    struct CHESSLIB_API Move
    {
        TPosition m_from;
        TPosition m_to;
    };

    bool IsPositionOnBoard(const TPosition& i_pos);

    bool CHESSLIB_API IsPositionOccupied(
        const Board& i_board, 
        const TPosition& i_position, 
        EColor i_color);
}
