#include <catch.hpp>

#include <ChessLib/Game.h>

TEST_CASE("ShouldCreateGame")
{
    SECTION("Creation")
    {
        Chess::Game game;
    }
}

TEST_CASE("ShouldDisallowWrongMoves")
{
	using namespace Chess;

	SECTION("ShouldDisallowMoveFromEmptyCell")
	{
		Chess::Game game;
		const bool allowed = game.MakeMoveIfAllowed(Move{ PositionFromString("e3"), PositionFromString("e4") });
		REQUIRE_FALSE(allowed);
	}
}
