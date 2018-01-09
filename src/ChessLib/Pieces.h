#pragma once

#include "Piece.h"

namespace Chess
{
	class Pawn : public Piece
	{
	public:
		Pawn(EColor i_color);
		~Pawn() = default;

		const std::string& GetString() const override;
		std::vector<TPosition> GetPossibleMoveTargets(
			const TPosition& i_from, const Board& i_board) const override;
	};

	class Bishop : public Piece
	{
	public:
		Bishop(EColor i_color);
		~Bishop() = default;

		const std::string& GetString() const override;
		std::vector<TPosition> GetPossibleMoveTargets(
			const TPosition& i_from, const Board& i_board) const override;
	};
}