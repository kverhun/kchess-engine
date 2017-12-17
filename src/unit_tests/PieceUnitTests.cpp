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

TEST_CASE("Should convert string to position")
{
    auto check_conversion = [](
        short i_idx1, short i_idx2, const std::string& i_input)
    {
        const Chess::TPosition expected{i_idx1, i_idx2};
        const auto conversion_result = Chess::PositionFromString(i_input);
        return expected == conversion_result;
    };

    SECTION("Corners")
    {
        REQUIRE(check_conversion(0, 0, "a1"));
        REQUIRE(check_conversion(7, 7, "h8"));
        REQUIRE(check_conversion(7, 0, "a8"));
        REQUIRE(check_conversion(0, 7, "h1"));
    }

    SECTION("Middle")
    {
        REQUIRE(check_conversion(3, 3, "d4"));
        REQUIRE(check_conversion(4, 4, "e5"));
    }
}