cmake_minimum_required(VERSION 3.14)
project(cpp_fundamentals)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_subdirectory(extern/googletest)

add_executable(exercise_1_tests
    exercise_1/src/intVector.cpp
    exercise_1/test/exercise_1_test.cpp
)
target_include_directories(exercise_1_tests PRIVATE exercise_1/src)
target_link_libraries(exercise_1_tests gtest_main)
include(GoogleTest)
gtest_discover_tests(exercise_1_tests)

add_executable(exercise_2_tests
    exercise_2/src/Vehicle.cpp
    exercise_2/src/Vehicles.cpp
    exercise_2/src/ServiceCenter.cpp
    exercise_2/test/exercise_2_tests.cpp
)
target_include_directories(exercise_2_tests PRIVATE exercise_2/src)
target_link_libraries(exercise_2_tests gtest_main)
gtest_discover_tests(exercise_2_tests)

add_executable(exercise_3_tests
    exercise_3/test/exercise_3_tests.cpp
    exercise_3/src/FileWrapper.cpp
)
target_include_directories(exercise_3_tests PRIVATE exercise_3/src)
target_link_libraries(exercise_3_tests gtest_main)
gtest_discover_tests(exercise_3_tests)

add_executable(exercise_4_tests
    exercise_4/test/exercise_4_tests.cpp
    # exercise_4/src/FileWrapper.cpp
)
target_include_directories(exercise_4_tests PRIVATE exercise_4/src)
target_link_libraries(exercise_4_tests gtest_main)
gtest_discover_tests(exercise_4_tests)
