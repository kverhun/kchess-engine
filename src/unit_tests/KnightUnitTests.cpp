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
        Board board;
        const auto b1 = PositionFromString("b1");
        REQUIRE(2 == board.GetPiece(b1)->get().GetPossibleMoveTargets(b1, board).size());
    }
}