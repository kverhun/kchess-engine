cmake_minimum_required(VERSION 3.5)

add_library(
    ChessLib SHARED Piece.h
                    Piece.cpp
                    Board.h
                    Board.cpp
                    Game.h
                    Game.cpp
)