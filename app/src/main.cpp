#include <iostream>
#include <map>
#include <string>

#include "Piece.h"

namespace 
{
    using TBoard = std::map<Chess::TPosition, Chess::Piece>;
    
    std::string _BoardToString(const TBoard& i_board)
    {
        std::map<Chess::TPosition, std::string> text_board;
        for (char c = 'a'; c <= 'h'; ++c)
        {
            for (auto r = 1u; r <= 8; ++r)
            {
                if (i_board.find({c,r}) != i_board.end())
                    text_board[{c,r}] = i_board.at({c,r}).GetString();
                else
                    text_board[{c,r}] = "-";
            }
        }
        std::string res = "";
        for (auto r = 1u; r <= 8; ++r)
        {
            for (auto c = 'a'; c <= 'h'; ++c)
                res.append(text_board[{c,r}]);
            res.append("\n");
        }
        return res;
    }

    void _CreateAndPrintBoard()
    {
        using Chess::Piece;
        using TPosition = Chess::TPosition;
        std::map<TPosition, Piece> board_state;
        
        for (auto pos : {TPosition{'a',1}, TPosition{'h', 1}, TPosition{'a', 8}, TPosition{'h', 8}})
            board_state.emplace(pos, Piece("R"));
        for (auto pos : {TPosition{'b',1}, TPosition{'g',1}, TPosition{'b',8}, TPosition{'g', 8}})
            board_state.emplace(pos, Piece("N"));
        for (auto pos : {TPosition{'c',1}, TPosition{'f',1}, TPosition{'c',8}, TPosition{'f',8}})
            board_state.emplace(pos, Piece("B"));
        for (auto pos : {TPosition{'d',1}, TPosition{'d',8}})
            board_state.emplace(pos, Piece("Q"));
        for (auto pos : {TPosition{'e',1}, TPosition{'e',8}})
            board_state.emplace(pos, Piece("K"));
        for (auto row : {2, 7})
            for (auto c = 'a'; c <= 'h'; ++c)
                board_state.emplace(TPosition{c,row}, Piece("p"));

        const auto str = _BoardToString(board_state);
        std::cout << str;
    }
}

int main(int i_argc, char** ip_argv)
{
    _CreateAndPrintBoard();
    return 0;
}