cmake_minimum_required(VERSION 3.14)
project(cpp_fundamentals)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_subdirectory(extern/googletest)

add_executable(int_vector_tests
    ptr_ref_const/src/intVector.cpp
    ptr_ref_const/test/intVector_test.cpp
)

target_include_directories(int_vector_tests PRIVATE ptr_ref_const/src)

target_link_libraries(int_vector_tests gtest_main)

include(GoogleTest)
gtest_discover_tests(int_vector_tests)
