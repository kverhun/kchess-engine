#include "Pieces.h"

#include "Board.h"

namespace Chess
{
	Knight::Knight(EColor i_color)
		: Piece(i_color)
	{
	}

	const std::string& Knight::GetString() const
	{
		return "K";
	}

	std::vector<TPosition> Knight::GetPossibleMoveTargets(
		const TPosition& i_from, const Board& i_board) const
	{
		return Piece::GetPossibleMoveTargets(i_from, i_board);
	}
}