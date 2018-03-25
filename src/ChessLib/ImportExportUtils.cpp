#include "ImportExportUtils.h"

#include <sstream>

using namespace Chess::IO;

std::vector<std::string> Chess::IO::TokenizeString(const std::string& i_line, const char i_delimiter)
{
    std::vector<std::string> res;

    std::stringstream ss(i_line);
    std::string item;
    while (std::getline(ss, item, i_delimiter))
        res.push_back(item);

    return res;
}