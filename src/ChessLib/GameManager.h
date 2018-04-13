#pragma once

#include "Common.h"

#include <iostream>

namespace Chess
{
    class IPlayer;

    class GameManager
    {
    public:
        enum class EGameResult
        {
            WhiteWin,
            BlackWin,
            Draw
        };

        using TOptionalStream = std::optional<std::reference_wrapper<std::ostream>>;
        static EGameResult PerformGame(
            IPlayer& i_player_white, IPlayer& i_player_black,
            TOptionalStream i_log_summary = std::nullopt,
            TOptionalStream i_log_verbose = std::nullopt);
    };
}