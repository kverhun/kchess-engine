#pragma once

#include "ChesslibAPI.h"
#include "Piece.h"

#include <map>
#include <memory>

namespace Chess
{
    namespace detail
    {
        void PieceCustomDeleted(Piece*);
    }

    class CHESSLIB_API Board
    {
    public:
        Board();
        Board(const Board&) = delete;
        Board& operator=(const Board&) = delete;

        std::string ToString() const;

        void MakeMove(const Move& i_move);

        //using TPiecePtr = std::unique_ptr<Piece, decltype(detail::PieceCustomDeleted)>;
        //TPiecePtr GetPieceOnPosition(const TPosition& i_position) const;

        std::unique_ptr<const Piece> GetPieceOnPosition(const TPosition& i_position) const;
    private:
        std::map<TPosition, Piece> m_board_state;
    };
}