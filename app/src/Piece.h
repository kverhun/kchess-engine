#pragma once

#include <string>
#include <utility>

namespace Chess
{
    using TPosition = std::pair<char, unsigned short>;
    
    class Piece
    {
    public:
        Piece(const std::string& i_string_representation);
        Piece(const Piece&) = default;
        Piece& operator=(const Piece&) = default;
        
        const std::string& GetString() const;
    private:
        std::string m_string_representation;
    
    };
}