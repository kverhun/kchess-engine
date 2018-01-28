#include <catch.hpp>

#include <ChessLib/Common.h>
#include <ChessLib/Board.h>

using namespace Chess;

TEST_CASE("IsPositionOccupied")
{
    SECTION("IsPositionOccupied_01")
    {
        Board board;
        REQUIRE(Chess::IsPositionOccupied(board, PositionFromString("a1"), EColor::White));
        REQUIRE(Chess::IsPositionOccupied(board, PositionFromString("a2"), EColor::White));
        REQUIRE_FALSE(Chess::IsPositionOccupied(board, PositionFromString("a1"), EColor::Black));
        REQUIRE_FALSE(Chess::IsPositionOccupied(board, PositionFromString("a2"), EColor::Black));

        REQUIRE(Chess::IsPositionOccupied(board, PositionFromString("a7"), EColor::Black));
        REQUIRE(Chess::IsPositionOccupied(board, PositionFromString("a8"), EColor::Black));
        REQUIRE_FALSE(Chess::IsPositionOccupied(board, PositionFromString("a7"), EColor::White));
        REQUIRE_FALSE(Chess::IsPositionOccupied(board, PositionFromString("a8"), EColor::White));

    }
}