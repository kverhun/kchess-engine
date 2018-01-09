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
	SECTION("StartMove_White")
	{
		Board board;
		const auto white_pos = PositionFromString("e2");
		const auto white_pawn = board.GetPiece(white_pos);
		const auto white_possible_targets = white_pawn->get().GetPossibleMoveTargets(white_pos, board);
		REQUIRE(2 == white_possible_targets.size());
		REQUIRE(_Contains(white_possible_targets, PositionFromString("e3")));
		REQUIRE(_Contains(white_possible_targets, PositionFromString("e4")));
	}

	SECTION("StartMove_Black")
	{
		Board board;
		const auto black_pos = PositionFromString("e7");
		const auto black_pawn = board.GetPiece(black_pos);
		const auto black_possible_targets = black_pawn->get().GetPossibleMoveTargets(black_pos, board);
		REQUIRE(2 == black_possible_targets.size());
		REQUIRE(_Contains(black_possible_targets, PositionFromString("e6")));
		REQUIRE(_Contains(black_possible_targets, PositionFromString("e5")));
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