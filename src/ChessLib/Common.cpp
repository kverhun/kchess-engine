#include "Common.h"

#include "Board.h"

using namespace Chess;

namespace
{
    TPosition _ApplyShift(const TPosition& i_pos, const TPosition& i_shift)
    {
        return TPosition{ i_pos.first + i_shift.first, i_pos.second + i_shift.second };
    }

    std::vector<TPosition> _GenerateDiag(const TPosition& i_pos, const TPosition& i_shift)
    {
        std::vector<TPosition> res;
        res.push_back(i_pos);
        while (Chess::IsPositionOnBoard(_ApplyShift(res.back(), i_shift)))
            res.push_back(_ApplyShift(res.back(), i_shift));
        return res;
    }
}

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

TPositions Chess::GetRank(const TPosition& i_position)
{
    TPositions res;

    for (short i = 0; i < 8; ++i)
        res.emplace_back(i_position.first, i);

    return res;
}

TPositions Chess::GetFile(const TPosition& i_position)
{
    TPositions res;

    for (short i = 0; i < 8; ++i)
        res.emplace_back(i, i_position.second);

    return res;
}

std::pair<TPositions, TPositions> Chess::GetDiagonals(const TPosition& i_position)
{
    std::pair<TPositions, TPositions> res;

    auto process_shift = [&](TPositions& io_target, const TPosition& i_shift)
    {
        const auto diag = _GenerateDiag(i_position, i_shift);
        for (const auto& pos : diag)
            io_target.push_back(pos);
    };

    process_shift(res.first, TPosition{1,1});
    process_shift(res.first, TPosition{-1,-1});

    process_shift(res.second, TPosition{1,-1});
    process_shift(res.second, TPosition{-1,1});

    return res;
}
