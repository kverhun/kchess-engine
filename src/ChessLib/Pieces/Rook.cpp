#include "Pieces.h"

#include "Board.h"
#include "Common.h"

#include <set>

namespace Chess
{
    Rook::Rook(EColor i_color)
        : Piece(i_color)
    {
    }

    const std::string& Rook::GetString() const
    {
        static const std::string g_rook_str_white = "R";
        static const std::string g_rook_str_black = "r";
        return GetColor() == EColor::White ? g_rook_str_white : g_rook_str_black;
    }

    std::vector<TPosition> Rook::GetPossibleMoveTargets(
        const TPosition& i_from, const Board& i_board) const
    {
        std::vector<TPosition> targets;

        std::set<TPosition> directions = {
            TPosition{1, 0}, TPosition{0, 1}, TPosition{-1, 0}, TPosition{0, -1},
        };

        for (const auto direction : directions)
        {
            const auto positions = GoInDiretionWhilePossible(i_from, direction, i_board, GetColor());
            for (const auto& pos : positions)
                targets.push_back(pos);
        }

        return targets;
    }
}