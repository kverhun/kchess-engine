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

TEST_CASE("Bishop_ShouldReturnCorrectMoveTargets")
{
    SECTION("01")
    {
        Board board;
        const auto d2 = PositionFromString("d2");
        const auto d4 = PositionFromString("d4");
        const auto d7 = PositionFromString("d7");
        const auto d5 = PositionFromString("d5");

        board.MakeMove({ d2, d4 });
        board.MakeMove({ d7, d5 });

        const auto c1 = PositionFromString("c1");
        const auto c1_targets = board.GetPiece(c1)->get().GetPossibleMoveTargets(c1, board);
        REQUIRE(c1_targets.size() > 0);

    }
}