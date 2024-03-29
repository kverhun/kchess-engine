#include "Piece.h"

#include <stdexcept>

namespace Chess
{
    bool CheckPositionString(const std::string& i_str)
    {
        if (i_str.size() != 2)
            return false;
        const auto s1 = i_str[0];
        if (s1 < 'a' || s1 > 'h')
            return false;
        const auto s2 = i_str[1];
        if (s2 < '1' || s2 > '8')
            return false;
        return true;
    }

    TPosition PositionFromString(const std::string& i_str)
    {
        if (!CheckPositionString(i_str))
            throw std::logic_error("Attempt to construct position from invalid string");
        const auto col = i_str[0];
        const auto col_converted = static_cast<short>(col - 'a');
        const auto row = i_str[1];
        const auto row_converted = static_cast<short>(row - '1');
        return { row_converted, col_converted };
    }

    std::string PositionToString(const TPosition& i_pos)
    {
        const char file = i_pos.second + 'a';
        const char rank = i_pos.first + '1';
        return std::string(1, file) + std::string(1, rank);
    }

    Piece::Piece(EColor i_color)
        : m_color(i_color)
    {}

    Piece::Piece(const std::string& i_string_representation)
        : m_string_representation(i_string_representation)
        , m_color(EColor::White)
    {}

    const std::string& Piece::GetString() const
    {
        return m_string_representation;
    }

    const EColor Piece::GetColor() const
    {
        return m_color;
    }

    std::vector<TPosition> Piece::GetPossibleMoveTargets(
        const TPosition & i_from, const Board& i_board) const
    {
        std::vector<TPosition> res;
        for (short row = 0; row < 8; ++row)
            for (short col = 0; col < 8; ++col)
                res.push_back(TPosition{ row, col });
        return res;
    }
}