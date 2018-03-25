#pragma once

#include "ChesslibAPI.h"
#include "Piece.h"


#ifdef __APPLE__
#include <experimental/optional>
namespace std
{
    using experimental::optional;
    using experimental::nullopt;
    using experimental::make_optional;
}
#else
#include <optional>
#endif

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

    private:
        std::map<TPosition, std::unique_ptr<const Piece>> m_board_state;
    };
}