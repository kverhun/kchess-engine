#pragma once

#include "ChesslibAPI.h"
#include "Common.h"

#include <string>
#include <vector>

namespace Chess
{
    bool CHESSLIB_API CheckPositionString(const std::string& i_str);

    TPosition CHESSLIB_API PositionFromString(const std::string& i_str);

    class Board;

    class CHESSLIB_API Piece
    {
    public:
        Piece(const std::string& i_string_representation);
        
        Piece(const Piece&) = delete;
        Piece& operator=(const Piece&) = delete;
        Piece(Piece&&) = default;
        Piece& operator = (Piece&&) = default;
        
        virtual const std::string& GetString() const;

		const EColor GetColor() const;

        virtual std::vector<TPosition> GetPossibleMoveTargets(
            const TPosition& i_from, const Board& i_board) const;

	protected:
		Piece(EColor i_color);

    private:
		const EColor m_color;
        const std::string m_string_representation;
    
    };
}