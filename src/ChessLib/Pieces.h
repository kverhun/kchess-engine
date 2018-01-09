#pragma once

#include "Piece.h"

namespace Chess
{
	class Pawn : public Piece
	{
	public:
		Pawn() = default;
		~Pawn() = default;

		const std::string& GetString() const override;
		std::vector<TPosition> GetPossibleMoveTargets(
			const TPosition& i_from, const Board& i_board) const override;
	};
}