#pragma once

#include "ChesslibAPI.h"

#include <vector>
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

    using TPositions = std::vector<TPosition>;
    
    TPositions CHESSLIB_API GetRank(const TPosition& i_position);
    TPositions CHESSLIB_API GetFile(const TPosition& i_position);
    
    std::pair<TPositions, TPositions> CHESSLIB_API GetDiagonals(const TPosition& i_position);
}
