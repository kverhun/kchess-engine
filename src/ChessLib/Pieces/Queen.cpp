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

        std::set<TPosition> directions = {
            TPosition{1, 0}, TPosition{0, 1}, TPosition{-1, 0}, TPosition{0, -1},
            TPosition{1, 1}, TPosition{1, -1}, TPosition{-1, 1}, TPosition{-1, -1}};

        for (const auto direction : directions)
        {
            const auto positions = GoInDiretionWhilePossible(i_from, direction, i_board, GetColor());
            for (const auto& pos : positions)
                targets.push_back(pos);
        }

        return targets;
    }
}