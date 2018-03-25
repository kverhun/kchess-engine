#pragma once

#include "ChesslibAPI.h"

#include <string>
#include <vector>

namespace Chess
{
    namespace IO
    {
    
    std::vector<std::string> CHESSLIB_API TokenizeString(const std::string& i_line, const char i_delimiter);
    
    }
}
