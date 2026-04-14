cmake_minimum_required(VERSION 3.10)
project(formatter_ex_lib)

add_subdirectory(formatter_lib)
add_library(formatter_ex STATIC formatter_ex.cpp)
target_include_directories(formatter_ex PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(formatter_ex PUBLIC formatter)
set_target_properties(formatter_ex PROPERTIES CXX_STANDARD 11)
