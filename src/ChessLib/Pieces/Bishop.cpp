#include "Pieces.h"

#include "Board.h"

#include <algorithm>
#include <set>

using namespace Chess;

namespace Chess
{
    Bishop::Bishop(EColor i_color)
        : Piece(i_color)
    {
    }

    const std::string& Bishop::GetString() const
    {
        static const std::string g_bishop_str_white = "B";
        static const std::string g_bishop_str_black = "b";
        return GetColor() == EColor::White ? g_bishop_str_white : g_bishop_str_black;
    }

    std::vector<TPosition> Bishop::GetPossibleMoveTargets(
        const TPosition& i_from, const Board& i_board) const
    {
        std::vector<TPosition> targets;
        
        std::set<TPosition> directions = {
            TPosition{1, 1}, TPosition{1, -1}, TPosition{-1, 1}, TPosition{-1, -1}
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