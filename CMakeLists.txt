cmake_minimum_required(VERSION 3.14)
project(print)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(print STATIC ${CMAKE_CURRENT_SOURCE_DIR}/sources/print.cpp)

add_executable(example1 examples/example1.cpp)
target_link_libraries(example1 print)

add_executable(example2 examples/example2.cpp)
target_link_libraries(example2 print)

option(BUILD_EXAMPLES "Build examples" OFF)
option(BUILD_TESTS "Build tests" OFF)

if(BUILD_EXAMPLES)
  add_subdirectory(formatter_lib)
  add_subdirectory(formatter_ex_lib)
  add_subdirectory(solver_lib)

  add_executable(hello_world_application hello_world_application/hello_world.cpp)
  target_link_libraries(hello_world_application print formatter_ex)

  add_executable(solver_application solver_application/equation.cpp)
  target_link_libraries(solver_application print solver_lib)
endif()

if(BUILD_TESTS)
  enable_testing()
  include(FetchContent)
  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
  )
  FetchContent_MakeAvailable(googletest)
  
  file(GLOB ${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)
  add_executable(check ${${PROJECT_NAME}_TEST_SOURCES})
  target_link_libraries(check print gtest_main)
  target_include_directories(check PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
  add_test(NAME check COMMAND check)
endif()

include(CPackConfig.cmake)

# Alias for solver (for packaging)
add_executable(solver solver_application/equation.cpp)
target_link_libraries(solver print formatter_ex formatter)

# Add include directories for solver
target_include_directories(solver PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/formatter_ex_lib
    ${CMAKE_CURRENT_SOURCE_DIR}/formatter_ex_lib/formatter_lib
)

# Ensure solver links with all required libraries
if(TARGET solver)
    target_link_libraries(solver print formatter_ex formatter)
endif()

# Formatter_ex library
add_library(formatter_ex STATIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/formatter_ex_lib/formatter_ex.cpp
)
target_link_libraries(formatter_ex formatter)
target_include_directories(formatter_ex PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/formatter_ex_lib
    ${CMAKE_CURRENT_SOURCE_DIR}/formatter_ex_lib/formatter_lib
)

# Formatter library
add_library(formatter STATIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/formatter_ex_lib/formatter_lib/formatter.cpp
)
target_include_directories(formatter PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/formatter_ex_lib/formatter_lib
)

# Installation rules
install(TARGETS solver
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/README.md
    DESTINATION share/doc/solver
)
