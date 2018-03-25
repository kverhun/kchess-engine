#include <catch.hpp>

#include <ChessLib/ImportExportUtils.h>

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
}