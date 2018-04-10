#pragma once

#include "ChesslibAPI.h"

#include "Common.h"

#include <string>
#include <vector>

namespace Chess
{
    namespace IO
    {
    
    std::vector<std::string> CHESSLIB_API TokenizeString(const std::string& i_line, const char i_delimiter);
    
    TState CHESSLIB_API FENStringToState(const std::string& i_fen_string);
    
    std::string CHESSLIB_API StateToFENString(const TState& i_state);
    }
}
