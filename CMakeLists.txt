cmake_minimum_required(VERSION 3.10)
project(solver VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Solver library
add_library(solver_lib STATIC
    solver_lib/solver.cpp
)
target_include_directories(solver_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Main executable
add_executable(solver main_solver.cpp)
target_link_libraries(solver solver_lib)

# Installation
install(TARGETS solver RUNTIME DESTINATION bin)
install(TARGETS solver_lib ARCHIVE DESTINATION lib)
install(FILES solver_lib/solver.h DESTINATION include)

# CPack configuration
include(CPackConfig.cmake)
