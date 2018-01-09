#include "Game.h"

namespace Chess
{
    bool Game::MakeMoveIfAllowed(const Move& i_move)
    {
		const auto piece = m_board.GetPiece(i_move.m_from);
		if (piece)
			return true;
		else 
			return false;
    }
}