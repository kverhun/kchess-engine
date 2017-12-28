cmake_minimum_required (VERSION 3.5)

add_executable(
    ChessApp main.cpp
             CLI.h
             CLI.cpp
             PlayerCLI.h
             PlayerCLI.cpp
)

target_link_libraries(
    ChessApp ChessLib
)

include_directories(..)