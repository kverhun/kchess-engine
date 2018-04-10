#pragma once

#include "ChesslibAPI.h"

#include <map>
#include <vector>
#include <utility>

#ifdef __APPLE__
#include <experimental/optional>
namespace std
{
    using experimental::optional;
    using experimental::nullopt;
    using experimental::make_optional;
}
#else
#include <optional>
#endif

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
        bool operator < (const Move& i_other) const
        {
            if (m_from < i_other.m_from)
                return true;
            else if (m_to < i_other.m_to)
                return true;
            else
                return false;
        }
        bool operator == (const Move& i_other) const 
        {
            return m_from == i_other.m_from && m_to == i_other.m_to;
        }
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

    TPositions CHESSLIB_API GoInDiretionWhilePossible(
        const TPosition& i_from, const TPosition& i_direction, 
        const Chess::Board& i_board, EColor i_color);

    bool CHESSLIB_API IsCheck(const Board& i_board, const EColor& i_color);

    std::vector<Move> CHESSLIB_API GetPossibleMoves(const Board& i_board, const EColor& i_color);
}
