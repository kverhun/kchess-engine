cmake_minimum_required (VERSION 3.5)

add_executable(
    ChessApp main.cpp
             Board.h
             Board.cpp
             CLI.h
             CLI.cpp
)

target_link_libraries(
    ChessApp ChessLib
)

include_directories(..)