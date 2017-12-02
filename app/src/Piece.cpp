#include "Piece.h"

namespace Chess
{
    Piece::Piece(const std::string& i_string_representation)
        : m_string_representation(i_string_representation)
    {}

    const std::string& Piece::GetString() const
    {
        return m_string_representation;
    }
}