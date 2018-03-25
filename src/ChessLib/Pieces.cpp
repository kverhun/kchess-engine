#include "Pieces.h"

namespace Chess
{
    std::unique_ptr<Piece> CreatePieceFromSingleLetter(char i_letter)
    {
        static const std::map<char, std::function<std::unique_ptr<Piece>()>> g_letter_to_creator = {
            { 'R', [](){return std::make_unique<Rook>(EColor::White);} }
        };
        return g_letter_to_creator.at(i_letter)();
    }
}