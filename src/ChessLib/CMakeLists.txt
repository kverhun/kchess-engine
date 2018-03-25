cmake_minimum_required(VERSION 3.5)

add_library(
    ChessLib SHARED ChesslibAPI.h
                    Common.h
                    Common.cpp
                    Piece.h
                    Piece.cpp
                    Board.h
                    Board.cpp
                    Game.h
                    Game.cpp
                    IPlayer.h
                    Pieces.h
                    Pieces.cpp
                    Pieces/Bishop.cpp
                    Pieces/King.cpp
                    Pieces/Knight.cpp
                    Pieces/Pawn.cpp
                    Pieces/Rook.cpp
                    Pieces/Queen.cpp
                    ImportExportUtils.h
                    ImportExportUtils.cpp
)

target_include_directories(ChessLib PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_compile_definitions(ChessLib PRIVATE CHESSLIB_EXPORT)
