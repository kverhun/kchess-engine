#include <catch.hpp>

#include <ChessLib/Board.h>
#include <ChessLib/Game.h>
#include <ChessLib/Pieces.h>
#include <ChessLib/ImportExportUtils.h>

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

TEST_CASE("QueenInitialPosition")
{
    SECTION("01")
    {
        Board board{GetInitialPosition()};
        for (const std::string queen_pos_str : {"d1", "d8"}) 
        {    
            const auto queen_pos = PositionFromString(queen_pos_str);
            const auto queen = board.GetPiece(queen_pos);
            const auto queen_targets = queen->get().GetPossibleMoveTargets(queen_pos, board);
            REQUIRE(queen_targets.empty());
        }
    }
}
TEST_CASE("QueenEmptyBoard")
{
    SECTION("TestOnEmptyBoard1")
    {
        const size_t row_and_file = 14;

        std::map<std::pair<std::string, std::string>, size_t> positions_to_test = {
            {{"8/8/8/3Q4/8/8/8/8 w KQkq - 0 1", "d5"}, 8+8+8+7-4},
            {{"8/8/8/1Q6/8/8/8/8 w KQkq - 0 1", "b5"}, 8+8+6+5-4},
            {{"2Q5/8/8/8/8/8/8/8 w KQkq - 0 1", "c8"}, 8+8+3+6-4},
            {{"8/8/8/8/8/8/7Q/8 w KQkq - 0 1", "h2"}, 8+8+2+7-4},
            {{"8/8/8/Q7/8/8/8/8 w KQkq - 0 1", "a5"}, 8+8+4+5-4},
            {{"Q7/8/8/8/8/8/8/8 w KQkq - 0 1", "a8"}, 8+8+8+1-4},
            {{"7Q/8/8/8/8/8/8/8 w KQkq - 0 1", "h8"}, 8+8+8+1-4},
            {{"8/8/8/8/8/8/8/Q7 w KQkq - 0 1", "a1"}, 8+8+8+1-4},
            {{"8/8/8/8/8/8/8/7Q w KQkq - 0 1", "h1"}, 8+8+8+1-4}
        };
        
        for (const auto& test_case : positions_to_test)
        {
            const std::string fen_string = test_case.first.first;
            const auto queen_pos = PositionFromString(test_case.first.second);
            Board board{IO::FENStringToState(fen_string)};
            const auto& queen = board.GetPiece(queen_pos)->get();
            const auto queen_move_targets = queen.GetPossibleMoveTargets(queen_pos, board);
            REQUIRE(test_case.second == queen_move_targets.size());
        }
    }
}
