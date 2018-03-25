#include "ImportExportUtils.h"

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
    return state;
}