#include <catch.hpp>

#include <ChessLib/Board.h>

using namespace Chess;

TEST_CASE("ShouldCreateBoard")
{
    SECTION("Creation")
    {
        Chess::Board board;
    }

    SECTION("ShouldAssignColors")
    {
        Chess::Board board;
        for (char row = 'a'; row <= 'h'; ++row)
        {
            const auto white_pawn = board.GetPiece(PositionFromString(
                std::string(1, row) + "2"));
            REQUIRE(EColor::White == white_pawn->get().GetColor());

            const auto black_pawn = board.GetPiece(PositionFromString(
                std::string(1, row) + "7"));
            REQUIRE(EColor::Black == black_pawn->get().GetColor());
        }
    }
}

TEST_CASE("ShouldMovePieces")
{
    SECTION("MovePiece01")
    {
        Chess::Board board;
        board.MakeMove({ Chess::PositionFromString("e2"), Chess::PositionFromString("e4") });
    }
}

TEST_CASE("ShouldReturnPieceOnPosition")
{
    SECTION("EmptyCellsOnStart")
    {
        Chess::Board board;
        const auto piece_opt = board.GetPiece(PositionFromString("e3"));
        for (char col = 'a'; col <= 'g'; ++col)
            for (int row = 3; row <= 6; ++row)
            {
                const auto pos = PositionFromString(std::string(1, col) + std::to_string(row));
                const auto piece_opt = board.GetPiece(pos);
                REQUIRE(std::nullopt == piece_opt);
            }
    }

    SECTION("OccupiedCellsOnStart")
    {
        Chess::Board board;
        const auto piece_opt = board.GetPiece(PositionFromString("e3"));
        for (char col = 'a'; col <= 'g'; ++col)
            for (int row : {1, 2, 7, 8})
            {
                const auto pos = PositionFromString(std::string(1, col) + std::to_string(row));
                const auto piece_opt = board.GetPiece(pos);
                REQUIRE(piece_opt.has_value());
            }
    }

}