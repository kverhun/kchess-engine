#pragma once

#include <utility>

namespace Chess
{
    using TPosition = std::pair<short, short>;

    struct Move
    {
        TPosition m_from;
        TPosition m_to;
    };
}