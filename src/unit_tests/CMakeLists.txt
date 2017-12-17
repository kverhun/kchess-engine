cmake_minimum_required (VERSION 3.5)

add_executable(
    app_unit_tests 
    app_unit_tests.cpp
)
add_dependencies(app_unit_tests Catch)
target_link_libraries(app_unit_tests PUBLIC Catch)
