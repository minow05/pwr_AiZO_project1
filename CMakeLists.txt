cmake_minimum_required(VERSION 3.24)
project(pwr_AiZO_project1)

# Fetch Google Test
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

# Add your main project executable
add_executable(pwr_AiZO_project1
        src/main.cpp
        src/SortingAlgorithm.cpp
        src/Shell.cpp
        src/Quick.cpp
        src/Insertion.cpp
        src/Heap.cpp
)

# Enable testing
enable_testing()

# Create a test executable
add_executable(test_SortingAlgorithm
        tests/test_SortingAlgorithm.cpp
)

# Link the test executable with Google Test
target_link_libraries(test_SortingAlgorithm
        GTest::gtest_main
)

# Include GoogleTest functionality
include(GoogleTest)

# Discover and register the tests
gtest_discover_tests(test_SortingAlgorithm)
