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
    Board::Board(const TState& i_state)
    {
        for (const auto& entry : i_state)
        {
            m_board_state.emplace(entry.first, CreatePieceFromSingleLetter(entry.second));
        }
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

    std::vector<Move> Board::GetAllPossibleMoves(const EColor& i_color) const
    {
        std::vector<Move> res;

        for (const auto& el : m_board_state)
        {
            if (el.second->GetColor() == i_color)
            {
                const auto targets = el.second->GetPossibleMoveTargets(el.first, *this);
                std::transform(targets.begin(), targets.end(), std::back_inserter(res),
                    [&](const TPosition& i_pos)
                    {
                        return Move{el.first, i_pos};
                    });
            }
        }

        return res;
    }
}
