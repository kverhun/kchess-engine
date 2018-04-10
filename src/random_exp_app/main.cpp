#include <ChessLib/Common.h>
#include <ChessLib/IPlayer.h>
#include <ChessLib/GameManager.h>

#include <fstream>
#include <functional>
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
    
    std::unique_ptr<std::ostream> p_log_stream;
    auto verbose_stream = [&]() -> GameManager::TOptionalStream
    {
        if (i_argc > 1)
        {
            const std::string log_folder = ip_argv[1];
            p_log_stream = std::make_unique<std::ofstream>(log_folder + "/log.txt");
            return std::make_optional(std::ref(*p_log_stream.get()));
        }
        else
            return std::nullopt;
    }();

    const auto game_result = GameManager::PerformGame(player_white, player_black, std::ref(std::cout), verbose_stream);
    
    std::cout << "Result: " << _GameResultToString(game_result);

    return 0;
}