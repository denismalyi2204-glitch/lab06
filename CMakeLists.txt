cmake_minimum_required(VERSION 3.14)
project(lab05)

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
