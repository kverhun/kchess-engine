#include <catch.hpp>

#include <ChessLib/Board.h>
#include <ChessLib/Game.h>
#include <ChessLib/Pieces.h>

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

TEST_CASE("Knight_ShouldReturnCorrectMoveTargets")
{
    SECTION("01")
    {
        Board board{GetInitialPosition()};
        const auto b1 = PositionFromString("b1");
        const auto& knight_piece = board.GetPiece(b1)->get();
        const auto possible_move_targets = knight_piece.GetPossibleMoveTargets(b1, board);
        REQUIRE(2 == possible_move_targets.size());
    }
}