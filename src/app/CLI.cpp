#include "CLI.h"

#include <sstream>
#include <vector>

namespace 
{
    std::vector<std::string> _Tokenize(const std::string& i_line, const char i_delimiter = ',')
    {
        std::vector<std::string> res;

        std::stringstream ss(i_line);
        std::string item;
        while (std::getline(ss, item, i_delimiter))
            res.push_back(item);

        return res;
    }

    bool _AskForMoveSingle(Chess::TPosition& o_from, Chess::TPosition& o_to)
    {
        std::string user_input;
        std::getline(std::cin, user_input);
        const auto splitted = _Tokenize(user_input, ' ');
        for (const auto& s : splitted)
            std::cout << s << '\n';
        if (splitted.size() != 2)
            return false;
        const auto from_str = splitted[0];
        const auto to_str = splitted[1];
        if (Chess::CheckPositionString(from_str) && Chess::CheckPositionString(to_str))
        {
            o_from = Chess::PositionFromString(from_str);
            o_to = Chess::PositionFromString(to_str);
            return true;
        }
        else
            return false;
    }

}

namespace CLI
{
    std::pair<Chess::TPosition, Chess::TPosition> AskForMove()
    {
        std::pair<Chess::TPosition, Chess::TPosition> res;
        do 
        {
            std::cout << "Enter move:\n";
        }
        while (!_AskForMoveSingle(res.first, res.second));
        return res;
    }
}