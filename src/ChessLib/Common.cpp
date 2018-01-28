#include "Common.h"

#include "Board.h"

using namespace Chess;

bool Chess::IsPositionOnBoard(const TPosition & i_pos)
{
    return i_pos.first >= 0 && i_pos.first <= 7
        && i_pos.second >= 0 && i_pos.second <= 7;
}

bool Chess::IsPositionOccupied(
    const Board& i_board,
    const TPosition& i_position,
    Chess::EColor i_color)
{
    const auto piece_opt = i_board.GetPiece(i_position);
    if (!piece_opt)
        return false;
    if (piece_opt->get().GetColor() == i_color)
        return true;
    else
        return false;
}
