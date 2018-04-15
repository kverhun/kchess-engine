#include <catch.hpp>

#include <ChessLib/Common.h>
#include <ChessLib/Board.h>
#include <ChessLib/Piece.h>
#include <ChessLib/ImportExportUtils.h>


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
        Board board{GetInitialPosition()};
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

TEST_CASE("GenerateFilesTests")
{
    SECTION("GenerateFiles-TestAllFiles")
    {
        for (char c = 'a'; c <= 'h'; ++c)
        {
            const auto file_str = std::string(1, c);
            static const std::vector<std::string> rank_strs = {"1", "2", "3", "4", "5", "6", "7", "8"};
            
            for (std::string rank_str : rank_strs)
            {
                const auto pos_str = file_str + rank_str;
                const auto res = Chess::GetFile(PositionFromString(pos_str));

                const std::set<std::string> expected_res_strs = [&]()
                {
                    std::set<std::string> res;
                    for (const auto& rank_str : rank_strs)
                        res.insert(file_str + rank_str);
                    return res;
                }();

                const auto actual_res_strs = _GetStringSetFromPositions(res);

                REQUIRE(expected_res_strs == actual_res_strs);
            }
        }        
    }
}

TEST_CASE("GoInDiretionWhilePossible")
{
    SECTION("Test_01")
    {
        const std::string pos_str = "8/8/8/3Q4/8/8/8/8 w KQkq - 0 1";
        const auto pos = Chess::IO::FENStringToState(pos_str);
        Board board{pos};
        const TPosition shift_1{1,1};
        const auto res = GoInDiretionWhilePossible(PositionFromString("d5"), shift_1, board, EColor::White);
        REQUIRE(3 == res.size());
    }
}

TEST_CASE("DetectCheck")
{
    SECTION("StartPosition")
    {
        Board board{GetInitialPosition()};
        REQUIRE(Chess::IsCheck(board, EColor::White) == false);
        REQUIRE(Chess::IsCheck(board, EColor::Black) == false);
    }

    SECTION("DetectCheck_01")
    {
        const std::string pos_str = "8/8/8/3Q4/8/8/8/3k4 w KQkq - 0 1";
        Board board{IO::FENStringToState(pos_str)};
        REQUIRE(IsCheck(board, EColor::Black) == true);
        REQUIRE(IsCheck(board, EColor::White) == false);
    }

    SECTION("DetectCheck_02")
    {
        const std::string pos_str = "8/8/8/3Q4/8/8/3p4/3k4 w KQkq - 0 1";
        Board board{IO::FENStringToState(pos_str)};
        REQUIRE(IsCheck(board, EColor::Black) == false);
        REQUIRE(IsCheck(board, EColor::White) == false);
    }
}

TEST_CASE("ShouldNotAllowMoveWhichResultsInCheck")
{
    SECTION("01")
    {
        const std::string pos_str = "8/8/8/3Q4/8/8/8/3k4 w KQkq - 0 1";
        Board board{IO::FENStringToState(pos_str)};
        const auto moves = GetPossibleMoves(board, EColor::Black);
        REQUIRE(4 == moves.size());

        const auto moves_all = board.GetAllPossibleMoves(EColor::Black);
        REQUIRE(5 == moves_all.size());
    }

    SECTION("ScholarsMate")
    {
        const std::string pos_str = "r1bqkbnr/ppp2Qpp/2np4/4p3/2B1P3/8/PPPP1PPP/RNB1K1NR b KQkq - 0 4";
        Board board{IO::FENStringToState(pos_str)};
        const auto moves_black = GetPossibleMoves(board, EColor::Black);
        REQUIRE(moves_black.empty());
    }
}

TEST_CASE("ShouldDetectDrawPostiion")
{
    SECTION("01")
    {
        const std::string pos_str = "8/3k4/8/8/2K5/8/8/8  b KQkq - 0 4";
        Board board{IO::FENStringToState(pos_str)};
        REQUIRE(IsPositionDraw(board));
    }
}