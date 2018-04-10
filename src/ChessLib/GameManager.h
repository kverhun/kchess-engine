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

        static EGameResult PerformGame(
            IPlayer& i_player_white, IPlayer& i_player_black,
            std::optional<std::ostream> i_log);
    };
}