#include "Pieces.h"

#include "Board.h"

namespace Chess
{
    Pawn::Pawn(EColor i_color)
        : Piece(i_color)
    {
    }

    const std::string& Pawn::GetString() const
    {
        static const std::string g_pawn_str_white = "P";
        static const std::string g_pawn_str_black = "p";
        return GetColor() == EColor::White ? g_pawn_str_white : g_pawn_str_black;
    }

    std::vector<TPosition> Pawn::GetPossibleMoveTargets(
        const TPosition& i_from, const Board& i_board) const
    {
        std::vector<TPosition> targets;

        const int move_direction = GetColor() == EColor::White ? +1 : -1;
        const int start_position = GetColor() == EColor::White ? 1 : 6;

        if (i_board.GetPiece({i_from.first + move_direction, i_from.second}) == std::nullopt)
            targets.emplace_back(i_from.first + move_direction, i_from.second);

        if (i_from.first == start_position)
            targets.emplace_back(i_from.first + 2 * move_direction, i_from.second);

        for (const auto& capture_target : {
            TPosition{ i_from.first + move_direction, i_from.second - 1 },
            TPosition{ i_from.first + move_direction, i_from.second + 1 } })
        {
            const auto capture = i_board.GetPiece(capture_target);
            if (capture && capture->get().GetColor() != this->GetColor())
                targets.push_back(capture_target);
        }

        return targets;
    }
}