#pragma once

#include "ChesslibAPI.h"

#include <utility>

namespace Chess
{
    using TPosition = std::pair<short, short>;

    struct CHESSLIB_API Move
    {
        TPosition m_from;
        TPosition m_to;
    };
}