#include "Pieces.h"

#include "Board.h"

namespace Chess
{
	const std::string& Pawn::GetString() const
	{
		return "p";
	}

	std::vector<TPosition> Pawn::GetPossibleMoveTargets(
		const TPosition& i_from, const Board& i_board) const
	{
		std::vector<TPosition> targets;
		 
		targets.emplace_back(i_from.first, i_from.second + 1);
		
		if (i_from.second == 2)
			targets.emplace_back(i_from.first, i_from.second + 2);
		
		for (const auto& capture_target : { 
			TPosition{ i_from.first - 1, i_from.second + 1 }, 
			TPosition{ i_from.first + 1, i_from.second + 1 } })
		{
			const auto capture = i_board.GetPiece(capture_target);
			if (capture)
				targets.push_back(capture_target);
		}

		return targets;
	}
}