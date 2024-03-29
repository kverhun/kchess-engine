#include "Pieces.h"

#include "Board.h"
#include "Common.h"

namespace Chess
{
    King::King(EColor i_color)
        : Piece(i_color)
    {
    }

    const std::string& King::GetString() const
    {
        static const std::string g_king_str_white = "K";
        static const std::string g_king_str_black = "k";
        return GetColor() == EColor::White ? g_king_str_white : g_king_str_black;
    }

    std::vector<TPosition> King::GetPossibleMoveTargets(
        const TPosition& i_from, const Board& i_board) const
    {
        std::vector<TPosition> targets;

        const int ci = i_from.first;
        const int cj = i_from.second;

        for (auto i : {ci-1,ci,ci+1})
        {
            for (auto j : {cj-1,cj,cj+1})
            {
                if (i == ci && j == cj)
                    continue;
                if (IsPositionOccupied(i_board, {i,j}, GetColor()) 
                    || !IsPositionOnBoard({i,j}))
                    continue;
                targets.emplace_back(i, j);
            }
        }

        return targets;
    }
}