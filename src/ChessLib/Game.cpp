#include "Game.h"

using namespace Chess;

namespace
{
    bool _IsMoveAllowed(const Board& i_board, const Move& i_move, EColor i_color_to_move)
    {
        const auto piece = i_board.GetPiece(i_move.m_from);
        if (piece && piece->get().GetColor() == i_color_to_move)
        {
            const auto possible_targets = piece->get().GetPossibleMoveTargets(i_move.m_from, i_board);
            if (std::find(possible_targets.begin(), possible_targets.end(),
                i_move.m_to) != possible_targets.end())
            {
                return true;
            }
        }
        return false;
    }
}

namespace Chess
{
    Game::Game()
        : m_board(Chess::GetInitialPosition())
    {

    }

    const Board& Game::GetBoard() const
    {
        return m_board;
    }

    EColor Game::GetColorToMove() const
    {
        if (m_current_move_number % 2 == 0)
            return EColor::White;
        else
            return EColor::Black;
    }

    size_t Game::GetCurrentMoveNumber() const
    {
        return m_current_move_number;
    }

    bool Game::MakeMoveIfAllowed(const Move& i_move)
    {
        if (_IsMoveAllowed(m_board, i_move, GetColorToMove()))
        {
            m_board.MakeMove(i_move);
            ++m_current_move_number;
            return true;
        }
        else
            return false;
    }
}