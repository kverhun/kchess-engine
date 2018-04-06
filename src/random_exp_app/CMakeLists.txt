cmake_minimum_required (VERSION 3.5)

add_executable(
    RandomExperimentApp 
            main.cpp
)

target_link_libraries(
    RandomExperimentApp ChessLib
)

include_directories(..)