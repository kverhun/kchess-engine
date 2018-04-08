#include "ImportExportUtils.h"

#include <set>
#include <sstream>

using namespace Chess;
using namespace Chess::IO;

namespace 
{
    struct _FENInfo
    {
        std::vector<std::string> m_ranks;
        std::vector<std::string> m_other_info;
    };

    _FENInfo _FENStringToFENInfo(const std::string& i_fen_string)
    {
        _FENInfo info;

        const auto split_1 = TokenizeString(i_fen_string, '/');
        const auto split_2 = TokenizeString(split_1.back(), ' ');

        for (int i = 0; i < 7; ++i)
            info.m_ranks.push_back(split_1[i]);
        info.m_ranks.push_back(split_2.front());
        for (int i = 1; i < split_2.size(); ++i)
            info.m_other_info.push_back(split_2[i]);

        return info;
    }

    void _ParseFENRankToState(TState& io_state, int i_rank, const std::string& i_rank_str)
    {
        static const std::set<char> g_figure_chars = {'r', 'R', 'n', 'N', 'b', 'B', 'q', 'Q', 'k', 'K', 'p', 'P'};

        int cur_file_idx = 0;
        int cur_string_idx = 0;
        while(cur_file_idx < 8)
        {
            const char c = i_rank_str[cur_string_idx];
            if (g_figure_chars.count(c) > 0)
            {
                io_state.insert({TPosition{i_rank, cur_file_idx}, c});
                ++cur_file_idx;
            }
            else
            {
                const int num_empty = c - '0';
                cur_file_idx += num_empty;
            }
            ++cur_string_idx;
        }
    }
}

std::vector<std::string> Chess::IO::TokenizeString(const std::string& i_line, const char i_delimiter)
{
    std::vector<std::string> res;

    std::stringstream ss(i_line);
    std::string item;
    while (std::getline(ss, item, i_delimiter))
        res.push_back(item);

    return res;
}

TState Chess::IO::FENStringToState(const std::string& i_fen_string)
{
    TState state;

    const auto fen_info = _FENStringToFENInfo(i_fen_string);

    for (int i = 0; i < 8; ++i)
        _ParseFENRankToState(state, 8-i-1, fen_info.m_ranks[i]);

    return state;
}

std::string Chess::IO::StateToFENString(const TState& i_state)
{
    return "";
}