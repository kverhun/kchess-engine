#pragma once

#include <string>
#include <utility>

namespace Chess
{
    using TPosition = std::pair<short, short>;
    
    bool CheckPositionString(const std::string& i_str);

    TPosition PositionFromString(const std::string& i_str);

    class Piece
    {
    public:
        Piece(const std::string& i_string_representation);
        
        Piece(const Piece&) = delete;
        Piece& operator=(const Piece&) = delete;
        Piece(Piece&&) = default;
        Piece& operator = (Piece&&) = default;
        
        const std::string& GetString() const;
    private:
        const std::string m_string_representation;
    
    };
}