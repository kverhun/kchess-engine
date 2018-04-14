#include <ChessLib/Common.h>
#include <ChessLib/IPlayer.h>
#include <ChessLib/ImportExportUtils.h>
#include <ChessLib/GameManager.h>

#include <chrono>
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

    const auto timestamp_str = std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()).count());

    std::unique_ptr<std::ostream> p_log_stream;
    auto verbose_stream = [&]() -> GameManager::TOptionalStream
    {
        if (i_argc > 1)
        {
            const std::string log_folder = ip_argv[1];
            p_log_stream = std::make_unique<std::ofstream>(log_folder + "/log" + timestamp_str + ".txt");
            return std::make_optional(std::ref(*p_log_stream.get()));
        }
        else
            return std::nullopt;
    }();

    GameManager::GameInfo info;
    const auto game_result = GameManager::PerformGame(player_white, player_black, std::nullopt, std::nullopt, 
        std::make_optional((std::ref(info))));
    
    std::cout << timestamp_str << ", " << _GameResultToString(game_result) << ", " << info.m_moves.size() / 2 << '\n';

    if (i_argc > 1)
    {
        const std::string log_folder = ip_argv[1];
        auto log_stream = std::ofstream(log_folder + "/log" + timestamp_str + ".txt");
        log_stream << _GameResultToString(game_result);
        for (const auto& state : info.m_states)
            log_stream << IO::StateToFENString(state) << "\n";
        log_stream << "\n";
        for (const auto& move : info.m_moves)
            log_stream << PositionToString(move.m_from) << ' ' << PositionToString(move.m_to) << '\n';
    }

    return 0;
}