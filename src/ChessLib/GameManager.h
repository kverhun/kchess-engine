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
        
        struct GameInfo
        {   
            EGameResult m_result;
            std::vector<Move> m_moves;
            std::vector<TState> m_states;
        };

        using TOptionalStream = std::optional<std::reference_wrapper<std::ostream>>;
        using TOptionalGameInfo = std::optional<std::reference_wrapper<GameInfo>>;
        static EGameResult PerformGame(
            IPlayer& i_player_white, IPlayer& i_player_black,
            TOptionalStream i_log_summary = std::nullopt,
            TOptionalStream i_log_verbose = std::nullopt,
            TOptionalGameInfo i_game_info = std::nullopt
            );

    };
}