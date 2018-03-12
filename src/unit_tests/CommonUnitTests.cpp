#include <catch.hpp>

#include <ChessLib/Common.h>
#include <ChessLib/Board.h>
#include <ChessLib/Piece.h>

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

TEST_CASE("PositionToStringTests")
{
    SECTION("PositionToStringInverse")
    {
        std::set<std::string> positions = {
            "a1", "a2", "a3", "a4", "a5", "a6", "a7", "a8",
            "b1", "b2", "b3", "b4", "b5", "b6", "b7", "b8",
            "c1", "c2", "c3", "c4", "c5", "c6", "c7", "c8"
        };
        for (const auto& str_pos : positions)
        {
            const auto pos = PositionFromString(str_pos);
            const auto str_pos_converted = PositionToString(pos);
            REQUIRE(str_pos == str_pos_converted);
        }
    }
}

TEST_CASE("GenerateRankTests")
{
    SECTION("GenerateRank-01")
    {
        Board board;
        
    }
}

