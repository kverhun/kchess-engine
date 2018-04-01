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

    EColor _GetOppositeColor(const EColor& i_color)
    {
        if (i_color == EColor::White)
            return EColor::Black;
        else 
            return EColor::White;
    }
}

const TState& Chess::GetInitialPosition()
{
    static const std::map<std::string, char> g_pos_to_char = {
        {"a1", 'R'}, {"a2", 'P'}, /****/ {"a7", 'p'}, {"a8", 'r'},
        {"b1", 'N'}, {"b2", 'P'}, /****/ {"b7", 'p'}, {"b8", 'n'},
        {"c1", 'B'}, {"c2", 'P'}, /****/ {"c7", 'p'}, {"c8", 'b'},
        {"d1", 'Q'}, {"d2", 'P'}, /****/ {"d7", 'p'}, {"d8", 'q'},
        {"e1", 'K'}, {"e2", 'P'}, /****/ {"e7", 'p'}, {"e8", 'k'},
        {"f1", 'B'}, {"f2", 'P'}, /****/ {"f7", 'p'}, {"f8", 'b'},
        {"g1", 'N'}, {"g2", 'P'}, /****/ {"g7", 'p'}, {"g8", 'n'},
        {"h1", 'R'}, {"h2", 'P'}, /****/ {"h7", 'p'}, {"h8", 'r'}

    };
    static const TState g_initial_position = [&]()
    {
        TState state;
        for (const auto& e : g_pos_to_char)
            state.insert({PositionFromString(std::string(e.first)), e.second});
        return state;
    }();
    return g_initial_position;
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

TPositions Chess::GoInDiretionWhilePossible(
    const TPosition &i_from, const TPosition &i_direction, 
    const Chess::Board& i_board, Chess::EColor i_color)
{
    auto plus = [](const TPosition& i_pos, const TPosition& i_shift)
    {
        return TPosition{i_pos.first + i_shift.first, i_pos.second + i_shift.second};
    };

    TPositions res;

    TPosition current_pos = plus(i_from, i_direction);
    while(Chess::IsPositionOnBoard(current_pos) && !IsPositionOccupied(i_board, current_pos, i_color))
    {
        res.push_back(current_pos);
        if (IsPositionOccupied(i_board, current_pos, _GetOppositeColor(i_color)))
            break;
        current_pos = plus(current_pos, i_direction);
    }

    return res;
}

