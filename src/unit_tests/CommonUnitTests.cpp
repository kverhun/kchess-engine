#include <catch.hpp>

#include <ChessLib/Common.h>
#include <ChessLib/Board.h>
#include <ChessLib/Piece.h>

#include <set>

using namespace Chess;

namespace 
{
    std::set<std::string> _GetStringSetFromPositions(const TPositions& i_positions)
    {
        std::set<std::string> res;
        for (const auto& p : i_positions)
            res.insert(PositionToString(p));
        return res;
    }
}

TEST_CASE("IsPositionOccupied")
{
    SECTION("IsPositionOccupied_01")
    {
        Board board;
        REQUIRE(Chess::IsPositionOccupied(board, PositionFromString("a1"), EColor::White));
        REQUIRE(Chess::IsPositionOccupied(board, PositionFromString("a2"), EColor::White));
        REQUIRE_FALSE(Chess::IsPositionOccupied(board, PositionFromString("a1"), EColor::Black));
        REQUIRE_FALSE(Chess::IsPositionOccupied(board, PositionFromString("a2"), EColor::Black));

        REQUIRE(Chess::IsPositionOccupied(board, PositionFromString("a7"), EColor::Black));
        REQUIRE(Chess::IsPositionOccupied(board, PositionFromString("a8"), EColor::Black));
        REQUIRE_FALSE(Chess::IsPositionOccupied(board, PositionFromString("a7"), EColor::White));
        REQUIRE_FALSE(Chess::IsPositionOccupied(board, PositionFromString("a8"), EColor::White));

    }
}

TEST_CASE("PositionToStringTests")
{
    SECTION("PositionToStringInverse")
    {
        std::set<std::string> positions = {
            "a1", "a2", "a3", "a4", "a5", "a6", "a7", "a8",
            "b1", "b2", "b3", "b4", "b5", "b6", "b7", "b8",
            "c1", "c2", "c3", "c4", "c5", "c6", "c7", "c8"
        };
        for (const auto& str_pos : positions)
        {
            const auto pos = PositionFromString(str_pos);
            const auto str_pos_converted = PositionToString(pos);
            REQUIRE(str_pos == str_pos_converted);
        }
    }
}

TEST_CASE("GenerateRankTests")
{
    SECTION("GenerateRank-TestAllRanks")
    {
        Board board;

        for (int i = 1; i <= 8; ++i)
        {
            const auto rank_str = std::to_string(i);
            static const std::vector<std::string> file_strs = {"a", "b", "c", "d", "e", "f", "g", "h"};
            
            for (std::string file_str : file_strs)
            {
                const auto pos_str = file_str + rank_str;
                const auto res = Chess::GetRank(PositionFromString(pos_str));

                const std::set<std::string> expected_res_strs = [&]()
                {
                    std::set<std::string> res;
                    for (const auto& file_str : file_strs)
                        res.insert(file_str + rank_str);
                    return res;
                }();

                const auto actual_res_strs = _GetStringSetFromPositions(res);
                REQUIRE(expected_res_strs == actual_res_strs);
                
            }
        }

        
    }
}

