#include <catch.hpp>

#include <ChessLib/Board.h>
#include <ChessLib/Game.h>
#include <ChessLib/Pieces.h>

#include <algorithm>

using namespace Chess;

namespace
{
	bool _Contains(const std::vector<TPosition>& i_positions, const TPosition& i_position)
	{
		auto it = std::find(i_positions.begin(), i_positions.end(),
			i_position);
		return it != i_positions.end();
	}
}

TEST_CASE("ShouldReturnCorrectMoveTargets")
{
	SECTION("01")
	{
		Board board;
		const auto pos = PositionFromString("e2");
		const auto pawn = board.GetPiece(pos);
		const auto possible_targets = pawn->get().GetPossibleMoveTargets(pos, board);
		REQUIRE(2 == possible_targets.size());
		REQUIRE(_Contains(possible_targets, PositionFromString("e3")));
		REQUIRE(_Contains(possible_targets, PositionFromString("e4")));
	}

	SECTION("02")
	{
		Board board;
		board.MakeMove(Move{ PositionFromString("e2"), PositionFromString("e4") });
		board.MakeMove(Move{ PositionFromString("d7"), PositionFromString("d5") });

		const auto e4_targets = board.GetPiece(PositionFromString("e4"))->get()
			.GetPossibleMoveTargets(PositionFromString("e4"), board);
		REQUIRE(2 == e4_targets.size());
		REQUIRE(_Contains(e4_targets, PositionFromString("d5")));
		REQUIRE(_Contains(e4_targets, PositionFromString("e5")));
	}
}