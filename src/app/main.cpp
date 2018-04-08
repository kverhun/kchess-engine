#include <iostream>
#include <map>
#include <string>

#include "CLI.h"
#include "PlayerCLI.h"

#include <ChessLib/GameManager.h>
#include <ChessLib/Piece.h>

namespace 
{
    using EGameResult = Chess::GameManager::EGameResult;
    std::string _GameResultToString(const EGameResult& i_res)
    {
        const static std::map<EGameResult, std::string> g_result_to_string = {
            {EGameResult::WhiteWin, "White win"},
            {EGameResult::BlackWin, "Black win"},
            {EGameResult::Draw,     "Draw"}
        };
        return g_result_to_string.at(i_res);
    }
}

int main(int i_argc, char** ip_argv)
{
    PlayerCLI player_white;
    PlayerCLI player_black;

    const auto game_result = Chess::GameManager::PerformGame(
        player_white, player_black);

    std::cout << "Result: " << _GameResultToString(game_result);
    
    return 0;
}