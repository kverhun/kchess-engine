cmake_minimum_required (VERSION 3.5)

add_executable(
    app_unit_tests 
        app_unit_tests.cpp
        BoardUnitTests.cpp
        PieceUnitTests.cpp
        GameUnitTests.cpp
)

target_link_libraries(app_unit_tests PUBLIC ChessLib Catch)
include_directories(..)
