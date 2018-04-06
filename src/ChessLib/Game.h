#pragma once

#include "ChesslibAPI.h"

#include "Board.h"

namespace Chess
{
    class CHESSLIB_API Game
    {
    public:
        Game();
        
        const Board& GetBoard() const;
        bool MakeMoveIfAllowed(const Move& i_move);

        EColor GetColorToMove() const;

    private:
        Board m_board;
        size_t m_current_move_number = 0;
    };
}