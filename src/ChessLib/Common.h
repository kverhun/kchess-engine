#pragma once

#include <utility>

#ifdef CHESSLIB_EXPORT
#define CHESSLIB_API __declspec(dllexport)
#else
#define CHESSLIB_API __declspec(dllimport)
#endif

namespace Chess
{
    using TPosition = std::pair<short, short>;

    struct CHESSLIB_API Move
    {
        TPosition m_from;
        TPosition m_to;
    };
}