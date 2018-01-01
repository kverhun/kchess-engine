cmake_minimum_required(VERSION 3.5)

add_library(
    ChessLib SHARED ChesslibAPI.h
                    Common.h
                    Piece.h
                    Piece.cpp
                    Board.h
                    Board.cpp
                    Game.h
                    Game.cpp
                    IPlayer.h
)

target_compile_definitions(ChessLib PRIVATE CHESSLIB_EXPORT)
