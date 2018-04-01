#pragma once

#include "ChesslibAPI.h"

#include <map>
#include <vector>
#include <utility>

namespace Chess
{
    class Board;

    using TPosition = std::pair<short, short>;

    using TState = std::map<TPosition, char>;
    
    const TState& CHESSLIB_API GetInitialPosition();

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

    TPositions GoInDiretionWhilePredicate(
        const TPosition& i_from, const TPosition& i_direction,
        std::function<bool(const TPosition&)> i_predicate);
}
