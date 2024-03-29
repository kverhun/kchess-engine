#include <catch.hpp>

#include <ChessLib/Board.h>
#include <ChessLib/ImportExportUtils.h>

using namespace Chess;

TEST_CASE("ShouldCreateBoard")
{
    SECTION("Creation")
    {
        Chess::Board board{GetInitialPosition()};
    }

    SECTION("ShouldAssignColors_Pawns")
    {
        Chess::Board board{GetInitialPosition()};
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

    SECTION("ShouldAssignColors_Pieces")
    {
        Chess::Board board{GetInitialPosition()};
        for (char row = 'a'; row <= 'h'; ++row)
        {
            const auto white_piece = board.GetPiece(PositionFromString(
                std::string(1, row) + "1"));
            REQUIRE(EColor::White == white_piece->get().GetColor());

            const auto black_piece = board.GetPiece(PositionFromString(
                std::string(1, row) + "8"));
            REQUIRE(EColor::Black == black_piece->get().GetColor());
        }
    }
}

TEST_CASE("ShouldMovePieces")
{
    SECTION("MovePiece01")
    {
        Chess::Board board{GetInitialPosition()};
        board.MakeMove({ Chess::PositionFromString("e2"), Chess::PositionFromString("e4") });
    }
}

TEST_CASE("ShouldReturnPieceOnPosition")
{
    SECTION("EmptyCellsOnStart")
    {
        Chess::Board board{GetInitialPosition()};
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
        Chess::Board board{GetInitialPosition()};
        const auto piece_opt = board.GetPiece(PositionFromString("e3"));
        for (char col = 'a'; col <= 'g'; ++col)
            for (int row : {1, 2, 7, 8})
            {
                const auto pos = PositionFromString(std::string(1, col) + std::to_string(row));
                const auto piece_opt = board.GetPiece(pos);
                REQUIRE(piece_opt.operator bool());
            }
    }

}

TEST_CASE("GetAllAvailableMoves")
{
    SECTION("EmptyBoard")
    {
        Chess::Board board{IO::FENStringToState("8/8/8/8/8/8/8/8 w KQkq - 0 1")};
        
        const auto moves_white = board.GetAllPossibleMoves(EColor::White);
        REQUIRE(moves_white.empty());

        const auto moves_black = board.GetAllPossibleMoves(EColor::Black);
        REQUIRE(moves_black.empty());
    }

    SECTION("StartPosition")
    {
        Board board{GetInitialPosition()};
        const auto white_moves = board.GetAllPossibleMoves(EColor::White);
        REQUIRE(20 == white_moves.size());

        const auto black_moves = board.GetAllPossibleMoves(EColor::Black);
        REQUIRE(20 == black_moves.size());
    }

}

TEST_CASE("StateConversion")
{
    SECTION("01")
    {
        const std::set<std::string> test_positions = {
            "rnbqkbnr/pppppppQ/8/8/8/8/PPPPPPPP/RNB1KBNR w KQkq - 0 1",
            "8/8/8/8/8/8/8/8 w KQkq - 0 1",
            "8/8/8/3Q4/8/8/8/3k4 w KQkq - 0 1",
            "rnbqkbnr/pp1ppppp/8/2p5/4P3/8/PPPP1PPP/RNBQKBNR w KQkq c6 0 2",
            "rnbqkbnr/pp1ppppp/8/2p5/4P3/5N2/PPPP1PPP/RNBQKB1R b KQkq - 1 2"
        };
        
        for (const auto& pos_str : test_positions)
        {
            const auto state = IO::FENStringToState(pos_str);
            Board board{state};
            const auto state_from_board = board.GetState();
            REQUIRE(state == state_from_board);
        }
    }
}