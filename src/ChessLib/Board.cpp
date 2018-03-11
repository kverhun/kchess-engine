#include "Board.h"

#include "Pieces.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <initializer_list>
#include <vector>

namespace
{
    using Chess::TPosition;
    using Chess::Piece;

    std::vector<TPosition> _Convert(const std::initializer_list<std::string>& i_input)
    {
        std::vector<TPosition> res;
        std::transform(std::begin(i_input), std::end(i_input), std::back_inserter(res),
            [](const std::string& i_val)
        {
            return Chess::PositionFromString(i_val);
        });
        return res;
    }

    std::unique_ptr<const Piece> _CreatePiece(const std::string& i_string)
    {
        return std::make_unique<Piece>(i_string);
    }
}

namespace Chess
{
    Board::Board()
    {
        for (auto pos : { "a1", "h1", "a8", "h8" })
            m_board_state.emplace(PositionFromString(pos), 
                std::make_unique<Rook>(pos[1] == '1' ? EColor::White : EColor::Black));
        for (std::string pos : { "b1", "g1", "b8", "g8" })
            m_board_state.emplace(PositionFromString(pos), 
                std::make_unique<Knight>(pos[1] == '1' ? EColor::White : EColor::Black));
        for (std::string pos : {"f1", "c1", "c8", "f8"})
            m_board_state.emplace(PositionFromString(pos),
                std::make_unique<Bishop>(pos[1] == '1' ? EColor::White : EColor::Black));
        for (auto pos : _Convert({ "d1", "d8" }))
            m_board_state.emplace(pos, _CreatePiece("Q"));
        for (auto pos : { "e1", "e8" })
            m_board_state.emplace(PositionFromString(pos),
                std::make_unique<King>(pos[1] == '1' ? EColor::White : EColor::Black));

        for (const std::string row : {"2", "7"})
            for (char col = 'a'; col <= 'h'; ++col)
                m_board_state.emplace(Chess::PositionFromString(std::string(1, col) + row),
                    std::make_unique<Pawn>(row == "2" ? EColor::White : EColor::Black));
    }

    std::string Board::ToString() const
    {
        std::map<Chess::TPosition, std::string> text_board;
        for (auto c = 0; c < 8; ++c)
        {
            for (auto r = 0; r < 8; ++r)
            {
                if (m_board_state.find({ c,r }) != m_board_state.end())
                    text_board[{c, r}] = m_board_state.at({ c,r })->GetString();
                else
                    text_board[{c, r}] = "-";
            }
        }
        std::string res = "";
        for (auto r = 0; r < 8; ++r)
        {
            for (auto c = 0; c < 8; ++c)
                res.append(text_board[{c, r}]);
            res.append("\n");
        }
        return res;
    }

    void Board::MakeMove(const Move& i_move)
    {
        if (m_board_state.find(i_move.m_from) == m_board_state.end())
            throw std::logic_error("No piece on \'from\' position");

        m_board_state.erase(i_move.m_to);
        m_board_state.emplace(i_move.m_to, std::move(m_board_state.at(i_move.m_from)));
        m_board_state.erase(i_move.m_from);
    }

    Board::PieceOpt Board::GetPiece(const TPosition& i_position) const
    {
        auto piece_it = m_board_state.find(i_position);
        if (piece_it != m_board_state.end())
            return std::make_optional(std::ref(*piece_it->second.get()));
        else
            return std::nullopt;
    }
}
