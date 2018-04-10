#include <ChessLib/Common.h>
#include <ChessLib/IPlayer.h>
#include <ChessLib/GameManager.h>

#include <iostream>
#include <random>

using namespace Chess;

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

    class _RandomMovePlayer : public IPlayer
    {
    public:
        _RandomMovePlayer(EColor i_color)
            : m_color(i_color)
        {}

        Move GetMove(const Board& i_board)
        {
            const auto possible_moves = GetPossibleMoves(i_board, m_color);
            
            std::random_device rd; 
            std::mt19937 rng(rd());
            std::uniform_int_distribution<int> uni(0, possible_moves.size() - 1); 

            const auto random_idx = uni(rng);

            return possible_moves[random_idx];
        }

    private:
        const EColor m_color;
    };
}

int main(int i_argc, char** ip_argv)
{
    _RandomMovePlayer player_white{EColor::White};
    _RandomMovePlayer player_black(EColor::Black);

    const auto game_result = GameManager::PerformGame(player_white, player_black, std::ref(std::cout));
    
    std::cout << "Result: " << _GameResultToString(game_result);

    return 0;
}