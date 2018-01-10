#include "Pieces.h"

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

    std::vector<TPosition> _CutDiag(const std::vector<TPosition>& i_diag, const Board& i_board)
    {
        std::vector<TPosition> res = { i_diag.front() };

        const auto our_color = i_board.GetPiece(i_diag.front())->get().GetColor();
        for (auto i = 1u; i < i_diag.size(); ++i)
        {
            const auto cell_content = i_board.GetPiece(i_diag[i]);
            if (cell_content)
            {
                if (cell_content->get().GetColor() != our_color)
                    res.push_back(i_diag[i]);
                break;
            }
            else
                res.push_back(i_diag[i]);
        }
        return res;
    }

}

namespace Chess
{
    Bishop::Bishop(EColor i_color)
        : Piece(i_color)
    {
    }

    const std::string& Bishop::GetString() const
    {
        return "B";
    }

    std::vector<TPosition> Bishop::GetPossibleMoveTargets(
        const TPosition& i_from, const Board& i_board) const
    {
        std::vector<TPosition> res;
        for (TPosition shift : { TPosition{ 1,1 }, TPosition{ 1,-1 }, TPosition{ -1, 1 }, TPosition{ -1,-1 } })
        {
            const auto diag = _GenerateDiag(i_from, shift);
            const auto cut_diag = _CutDiag(diag, i_board);
            for (const auto& pos : cut_diag)
                res.push_back(pos);
        }
        return res;
    }
}