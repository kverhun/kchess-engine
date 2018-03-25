#pragma once

#include "ChesslibAPI.h"
#include "Piece.h"

namespace Chess
{
    std::unique_ptr<Piece> CHESSLIB_API CreatePieceFromSingleLetter(char i_letter);

    class Pawn : public Piece
    {
    public:
        Pawn(EColor i_color);
        ~Pawn() = default;

        const std::string& GetString() const override;
        std::vector<TPosition> GetPossibleMoveTargets(
            const TPosition& i_from, const Board& i_board) const override;
    };

    class Bishop : public Piece
    {
    public:
        Bishop(EColor i_color);
        ~Bishop() = default;

        const std::string& GetString() const override;
        std::vector<TPosition> GetPossibleMoveTargets(
            const TPosition& i_from, const Board& i_board) const override;
    };

    class Knight : public Piece
    {
    public:
        Knight(EColor i_color);
        ~Knight() = default;

        const std::string& GetString() const override;
        std::vector<TPosition> GetPossibleMoveTargets(
            const TPosition& i_from, const Board& i_board) const override;
    };

    class Rook : public Piece
    {
    public:
        Rook(EColor i_color);
        ~Rook() = default;

        const std::string& GetString() const override;
        std::vector<TPosition> GetPossibleMoveTargets(
            const TPosition& i_from, const Board& i_board) const override;
    };

    class King : public Piece
    {
    public:
        King(EColor i_color);
        ~King() = default;

        const std::string& GetString() const override;
        std::vector<TPosition> GetPossibleMoveTargets(
            const TPosition& i_from, const Board& i_board) const override;
    };

    class Queen : public Piece
    {
    public:
        Queen(EColor i_color);
        ~Queen() = default;

        const std::string& GetString() const override;
        std::vector<TPosition> GetPossibleMoveTargets(
            const TPosition& i_from, const Board& i_board) const override;
    };
}