#include "Pieces.h"

namespace
{
    template<typename T, Chess::EColor Color>
    std::unique_ptr<T> _Create()
    {
        return std::make_unique<T>(Color);
    }
}

namespace Chess
{
    std::unique_ptr<Piece> CreatePieceFromSingleLetter(char i_letter)
    {
        static const std::map<char, std::function<std::unique_ptr<Piece>()>> g_letter_to_creator = {
            { 'R', _Create<Rook, EColor::White> },
            { 'r', _Create<Rook, EColor::Black> },
            { 'N', _Create<Knight, EColor::White> },
            { 'n', _Create<Knight, EColor::Black> },
            { 'B', _Create<Bishop, EColor::White> },
            { 'b', _Create<Bishop, EColor::Black> },
            { 'Q', _Create<Queen, EColor::White> },
            { 'q', _Create<Queen, EColor::Black> },
            { 'K', _Create<King, EColor::White> },
            { 'k', _Create<King, EColor::Black> },
            { 'P', _Create<Pawn, EColor::White> },
            { 'p', _Create<Pawn, EColor::Black> }
        };
        return g_letter_to_creator.at(i_letter)();
    }
}