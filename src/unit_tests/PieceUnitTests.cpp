#include <catch.hpp>

#include <ChessLib/Piece.h>

#include <iostream>
#include <string>

TEST_CASE("ShouldCheckStringCorrectness")
{
    SECTION("Correct positions")
    {
        for (char col = 'a'; col <= 'h'; ++col)
        {
            for (int row = 1; row <= 8; ++row)
            {
                std::string position_str = {col};
                position_str.append(std::to_string(row));
                REQUIRE(Chess::CheckPositionString(position_str));
            }
        }
    }

    SECTION("Incorrect positions")
    {
        #define SHOULD_BE_INCORRECT(str) REQUIRE(!Chess::CheckPositionString((str)));

        SHOULD_BE_INCORRECT("a0");
        SHOULD_BE_INCORRECT("ab");
        SHOULD_BE_INCORRECT("ba");
        SHOULD_BE_INCORRECT("abc");
        SHOULD_BE_INCORRECT("a11");
        SHOULD_BE_INCORRECT("g1 ");
        SHOULD_BE_INCORRECT("b");
        SHOULD_BE_INCORRECT("");
        SHOULD_BE_INCORRECT(" ");
        
        #undef SHOULD_BE_INCORRECT
    }
}