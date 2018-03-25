#include "Pieces.h"

#include "Board.h"

#include <algorithm>

namespace Chess
{
    Knight::Knight(EColor i_color)
        : Piece(i_color)
    {
    }

    const std::string& Knight::GetString() const
    {
        static const std::string g_knight_str_white = "N";
        static const std::string g_knight_str_black = "n";
        return GetColor() == EColor::White ? g_knight_str_white : g_knight_str_black;
    }

    std::vector<TPosition> Knight::GetPossibleMoveTargets(
        const TPosition& i_from, const Board& i_board) const
    {
        std::vector<TPosition> targets;

        targets.emplace_back(i_from.first + 1, i_from.second + 2);
        targets.emplace_back(i_from.first + 1, i_from.second - 2);
        targets.emplace_back(i_from.first + 2, i_from.second + 1);
        targets.emplace_back(i_from.first + 2, i_from.second - 1);

        targets.emplace_back(i_from.first - 1, i_from.second + 2);
        targets.emplace_back(i_from.first - 1, i_from.second - 2);
        targets.emplace_back(i_from.first - 2, i_from.second + 1);
        targets.emplace_back(i_from.first - 2, i_from.second - 1);

        targets.erase(std::remove_if(targets.begin(), targets.end(),
            [&](const TPosition& i_pos) 
        {
            return !Chess::IsPositionOnBoard(i_pos) 
                || Chess::IsPositionOccupied(i_board, i_pos, this->GetColor());
        }), targets.end());

        return targets;
    }
}