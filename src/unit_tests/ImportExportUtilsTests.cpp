#include <catch.hpp>

#include <ChessLib/Board.h>
#include <ChessLib/ImportExportUtils.h>

#include <iostream>

using namespace Chess;
using namespace Chess::IO;

TEST_CASE("TokenizeTest")
{
    SECTION("Test01")
    {
        const std::string input_str = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
        const auto tokenize_result = TokenizeString(input_str, '/');
        REQUIRE(8 == tokenize_result.size());
    }

    SECTION("Test02")
    {
        const std::string input_str = "RNBQKBNR w KQkq - 0 1";
        const auto tokenize_result = TokenizeString(input_str, ' ');
        REQUIRE(6 == tokenize_result.size());
    }
}

TEST_CASE("ParseFENTest")
{
    SECTION("Initial position")
    {
        const std::string input_str = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
        const auto state = FENStringToState(input_str);

        REQUIRE(GetInitialPosition() == state);
    }

    SECTION("Test01")
    {
        const std::string input_str = "8/8/8/8/8/8/8/8 w KQkq - 0 1";
        const auto state = FENStringToState(input_str);
        REQUIRE(state.empty());
    }

    SECTION("Test02")
    {
        const std::string input_str = "8/3p4/8/8/8/8/8/8 w KQkq - 0 1";
        const auto state = FENStringToState(input_str);
        REQUIRE(1 == state.size());
        REQUIRE(state.count(TPosition{6,3}) == 1);
        REQUIRE(state.at(TPosition{6,3}) == 'p');
    }
}