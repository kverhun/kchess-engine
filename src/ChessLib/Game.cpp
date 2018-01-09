#include "Game.h"

using namespace Chess;

namespace
{
	bool _IsMoveAllowed(const Board& i_board, const Move& i_move)
	{
		const auto piece = i_board.GetPiece(i_move.m_from);
		if (piece)
			return true;
		else
			return false;
	}
}

namespace Chess
{
	const Board& Game::GetBoard() const
	{
		return m_board;
	}

	bool Game::MakeMoveIfAllowed(const Move& i_move)
    {
		if (_IsMoveAllowed(m_board, i_move))
		{
			m_board.MakeMove(i_move);
			return true;
		}
		else
			return false;
    }
}