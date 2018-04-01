#include "Pieces.h"

#include "Board.h"
#include "Common.h"

#include <set>

namespace Chess
{
    Queen::Queen(EColor i_color)
        : Piece(i_color)
    {
    }

    const std::string& Queen::GetString() const
    {
        static const std::string g_queen_str_white = "Q";
        static const std::string g_queen_str_black = "q";
        return GetColor() == EColor::White ? g_queen_str_white : g_queen_str_black;
    }

    std::vector<TPosition> Queen::GetPossibleMoveTargets(
        const TPosition& i_from, const Board& i_board) const
    {
        std::vector<TPosition> targets;

        auto check_and_append_pos = [&](const TPosition& i_pos) -> bool
        {
            if (!IsPositionOccupied(i_board, i_pos, GetColor()))
            {
                targets.push_back(i_pos);
                return true;
            }   
            else
                return false;
        };

        for (int i = i_from.first - 1; i >= 0; --i)
        {
            if (!check_and_append_pos({i, i_from.second}))
                break;
        }

        for (int i = i_from.first + 1; i <= 7; ++i)
        {
            if (!check_and_append_pos({i, i_from.second}))
                break;
        }

        for (int j = i_from.second - 1; j >= 0; --j)
        {
            if (!check_and_append_pos({i_from.first, j}))
                break;
        }

        for (int j = i_from.second + 1; j <= 7; ++j)
        {
            if (!check_and_append_pos({i_from.first, j}))
                break;
        }

        std::set<TPosition> shifts_diag = {
            TPosition{1,1}, TPosition{1,-1}, TPosition{-1,1}, TPosition{-1,-1}
        };



        return targets;
    }
}