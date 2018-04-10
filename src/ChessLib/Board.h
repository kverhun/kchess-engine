#pragma once

#include "ChesslibAPI.h"
#include "Piece.h"

#include <map>
#include <memory>

namespace Chess
{
    class CHESSLIB_API Board
    {
    public:
        Board(const TState& i_state);
        Board(const Board&) = delete;
        Board& operator=(const Board&) = delete;

        std::string ToString() const;

        void MakeMove(const Move& i_move);

        using PieceOpt = std::optional<std::reference_wrapper<const Piece>>;
        PieceOpt GetPiece(const TPosition& i_position) const;

        std::vector<Move> GetAllPossibleMoves(const EColor& i_color) const;

        TState GetState() const;
    private:
        std::map<TPosition, std::unique_ptr<const Piece>> m_board_state;
    };
}
