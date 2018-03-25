#include "Pieces.h"

namespace Chess
{
    std::unique_ptr<Piece> CreatePieceFromSingleLetter(char i_letter)
    {
        static const std::map<char, std::function<std::unique_ptr<Piece>()>> g_letter_to_creator = {
            { 'R', [](){return std::make_unique<Rook>(EColor::White);} },
            { 'r', [](){return std::make_unique<Rook>(EColor::Black);} },
            { 'N', [](){return std::make_unique<Knight>(EColor::White);}},
            { 'n', [](){return std::make_unique<Knight>(EColor::Black);}},
            { 'B', [](){return std::make_unique<Bishop>(EColor::White);}},
            { 'b', [](){return std::make_unique<Bishop>(EColor::Black);}},
            { 'Q', [](){return std::make_unique<Queen>(EColor::White);}},
            { 'q', [](){return std::make_unique<Queen>(EColor::Black);}},
            { 'K', [](){return std::make_unique<King>(EColor::White);}},
            { 'k', [](){return std::make_unique<King>(EColor::Black);}},
            { 'P', [](){return std::make_unique<Pawn>(EColor::White);}},
            { 'p', [](){return std::make_unique<Pawn>(EColor::Black);}}
        };
        return g_letter_to_creator.at(i_letter)();
    }
}