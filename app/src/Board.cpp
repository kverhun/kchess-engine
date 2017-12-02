#include "Board.h"

namespace Chess
{
    Board::Board()
    {
        for (auto pos : {TPosition{'a',1}, TPosition{'h', 1}, TPosition{'a', 8}, TPosition{'h', 8}})
            m_board_state.emplace(pos, Piece("R"));
        for (auto pos : {TPosition{'b',1}, TPosition{'g',1}, TPosition{'b',8}, TPosition{'g', 8}})
            m_board_state.emplace(pos, Piece("N"));
        for (auto pos : {TPosition{'c',1}, TPosition{'f',1}, TPosition{'c',8}, TPosition{'f',8}})
            m_board_state.emplace(pos, Piece("B"));
        for (auto pos : {TPosition{'d',1}, TPosition{'d',8}})
            m_board_state.emplace(pos, Piece("Q"));
        for (auto pos : {TPosition{'e',1}, TPosition{'e',8}})
            m_board_state.emplace(pos, Piece("K"));
        for (auto row : {2, 7})
            for (auto c = 'a'; c <= 'h'; ++c)
                m_board_state.emplace(TPosition{c,row}, Piece("p"));
    }

    std::string Board::ToString() const
    {
        std::map<Chess::TPosition, std::string> text_board;
        for (char c = 'a'; c <= 'h'; ++c)
        {
            for (auto r = 1u; r <= 8; ++r)
            {
                if (m_board_state.find({c,r}) != m_board_state.end())
                    text_board[{c,r}] = m_board_state.at({c,r}).GetString();
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

    void Board::Move(const TPosition& i_from, const TPosition& i_to)
    {
        if (m_board_state.find(i_from) == m_board_state.end())
            throw std::logic_error("No piece on \'from\' position");
        
        m_board_state.erase(i_to);
        m_board_state.emplace(i_to, m_board_state.at(i_from));
        m_board_state.erase(i_from);
    }
}