#pragma once

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
            IPlayer& i_player_white, IPlayer& i_player_black);
    };
}