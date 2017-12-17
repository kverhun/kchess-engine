#include "Piece.h"

#include <stdexcept>

namespace 
{
    bool _CheckPositionString(const std::string& i_str)
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
}

namespace Chess
{
    TPosition PositionFromString(const std::string& i_str)
    {
        if (!_CheckPositionString(i_str))
            throw std::logic_error("Attempt to construct position from invalid string");
        const auto col = i_str[0];
        const auto col_converted = static_cast<short>(col - 'a');
        const auto row = i_str[1];
        const auto row_converted = static_cast<short>(row - '1');
        return {row_converted, col_converted};
    }

    Piece::Piece(const std::string& i_string_representation)
        : m_string_representation(i_string_representation)
    {}

    const std::string& Piece::GetString() const
    {
        return m_string_representation;
    }
}