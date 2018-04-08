cmake_minimum_required (VERSION 3.5)

project(Chess-app)

include(ExternalProject)
find_package(Git REQUIRED)

ExternalProject_Add(
    catch_download
    PREFIX ${CMAKE_BINARY_DIR}/catch
    GIT_REPOSITORY https://github.com/philsquared/Catch.git
    GIT_TAG v1.10.0
    TIMEOUT 10
    UPDATE_COMMAND ""
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
)

ExternalProject_Get_Property(catch_download source_dir)

set(CATCH_INCLUDE_DIR ${source_dir}/single_include CACHE INTERNAL "${CMAKE_BINARY_DIR}/catch")

add_library(Catch INTERFACE)
add_dependencies(Catch catch_download)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(ChessLib)
add_subdirectory(app)
add_subdirectory(random_exp_app)
add_subdirectory(unit_tests)
