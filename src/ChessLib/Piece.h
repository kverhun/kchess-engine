#pragma once

#include "ChesslibAPI.h"
#include "Common.h"

#include <string>

namespace Chess
{
    bool CHESSLIB_API CheckPositionString(const std::string& i_str);

    TPosition CHESSLIB_API PositionFromString(const std::string& i_str);

    class CHESSLIB_API Piece
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