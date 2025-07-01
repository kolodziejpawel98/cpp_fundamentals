cmake_minimum_required(VERSION 3.14)
project(cpp_fundamentals)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_subdirectory(extern/googletest)

add_executable(ptr_ref_const_exec ptr_ref_const/src/example.cpp)
add_executable(ptr_ref_const_tests ptr_ref_const/test/example_test.cpp)
target_link_libraries(ptr_ref_const_tests gtest_main)
include(GoogleTest)
gtest_discover_tests(ptr_ref_const_tests)