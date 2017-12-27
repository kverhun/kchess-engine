#include <catch.hpp>

#include <ChessLib/Board.h>

TEST_CASE("ShouldCreateBoard")
{
    SECTION("Creation")
    {
        Chess::Board board;
    }
}

TEST_CASE("ShouldMovePieces")
{
    SECTION("MovePiece01")
    {
        Chess::Board board;
        board.Move(Chess::PositionFromString("e2"), Chess::PositionFromString("e4"));
    }
}