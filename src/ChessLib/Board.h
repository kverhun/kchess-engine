#pragma once

#include "ChesslibAPI.h"
#include "Piece.h"


#include <optional>

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

        using PieceOpt = std::optional<std::reference_wrapper<Piece>>;

    private:
        std::map<TPosition, Piece> m_board_state;
    };
}