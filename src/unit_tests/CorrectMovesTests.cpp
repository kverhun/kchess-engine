// 8/7K/8/8/4k3/8/8/r7 w KQkq - 0 1

#include <catch.hpp>

#include <ChessLib/Board.h>
#include <ChessLib/Common.h>
#include <ChessLib/ImportExportUtils.h>

#include <iostream>
#include <iterator>

using namespace Chess;
using namespace Chess::IO;

using TMoveStr = std::pair<std::string, std::string>;

TEST_CASE("TestIncorrectMoves")
{
    SECTION("Test01")
    {
        const auto fen_string = "8/7K/8/8/4k3/8/8/r7 w KQkq - 0 1";
        Board board{FENStringToState(fen_string)};
        const auto allowed_moves = GetPossibleMoves(board, EColor::Black);
        
        const std::vector<TMoveStr> expected_moves_str = {
            {"a1", "b1"},
            {"a1", "c1"},
            {"a1", "d1"},
            {"a1", "e1"},
            {"a1", "f1"},
            {"a1", "g1"},
            {"a1", "h1"},
            {"a1", "a2"},
            {"a1", "a3"},
            {"a1", "a4"},
            {"a1", "a5"},
            {"a1", "a6"},
            {"a1", "a7"},
            {"a1", "a8"},
            {"e4", "d3"},
            {"e4", "e3"},
            {"e4", "f3"},
            {"e4", "d4"},
            {"e4", "f4"},
            {"e4", "d5"},
            {"e4", "e5"},
            {"e4", "f5"}
        };
        const std::set<Move> expected_moves = [&]()
        {
            std::set<Move> res;
            std::transform(expected_moves_str.begin(), expected_moves_str.end(), std::inserter(res, res.begin()),
                [](const TMoveStr& i_move_str) 
                {
                    return Move{PositionFromString(i_move_str.first), PositionFromString(i_move_str.second)};
                });
            return res;
        }();
        const std::set<Move> actual_moves(allowed_moves.begin(), allowed_moves.end());
        REQUIRE(expected_moves == actual_moves);
    }
}