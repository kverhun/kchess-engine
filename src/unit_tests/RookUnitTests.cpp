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

TEST_CASE("RookInitialPosition")
{
    SECTION("01")
    {
        Board board{GetInitialPosition()};
        for (const std::string rook_pos_str : {"a1", "h1", "a8", "h8"}) 
        {    
            const auto rook_pos = PositionFromString(rook_pos_str);
            const auto rook = board.GetPiece(rook_pos);
            const auto rook_targets = rook->get().GetPossibleMoveTargets(rook_pos, board);
            REQUIRE(rook_targets.empty());
        }
    }

    SECTION("TestOnEmptyBoard1")
    {
        std::map<std::string, std::string> positions_to_test = {
            {"8/8/8/3R4/8/8/8/8 w KQkq - 0 1", "d5"},
            {"8/8/8/1R6/8/8/8/8 w KQkq - 0 1", "b5"},
            {"2R5/8/8/8/8/8/8/8 w KQkq - 0 1", "c8"},
            {"8/8/8/8/8/8/7R/8 w KQkq - 0 1", "h2"},
            {"8/8/8/R7/8/8/8/8 w KQkq - 0 1", "a5"}
        };
        
        for (const auto& test_case : positions_to_test)
        {
            const std::string fen_string = test_case.first;
            const auto rook_pos = PositionFromString(test_case.second);
            Board board{IO::FENStringToState(fen_string)};
            const auto& rook = board.GetPiece(rook_pos)->get();
            const auto rook_move_targets = rook.GetPossibleMoveTargets(rook_pos, board);
            REQUIRE(14 == rook_move_targets.size());
        }
    }

}