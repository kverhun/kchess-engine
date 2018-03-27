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
}