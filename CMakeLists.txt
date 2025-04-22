cmake_minimum_required(VERSION 3.24)
project(pwr_AiZO_project1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.0
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM
)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(SFML googletest)

# Add the main executable
add_executable(pwr_AiZO_project1
        src/main.cpp
        src/Shell.cpp
        src/Quick.cpp
        src/Insertion.cpp
        src/Heap.cpp
        src/UserInterface.cpp
        include/Algorithms/SortingAlgorithm.h
        src/Checkbox.cpp
        src/SlideBar.cpp
        src/CheckboxGroup.cpp
        src/Dropdown.cpp
        include/UI/Button.h
        src/Button.cpp
)

target_include_directories(pwr_AiZO_project1 PRIVATE include)

target_link_libraries(pwr_AiZO_project1 PRIVATE SFML::Graphics)

enable_testing()

add_executable(tests
        tests/test_sizeOneArray.cpp
        src/Heap.cpp
        src/Quick.cpp
        src/Shell.cpp
        src/Insertion.cpp
)

target_include_directories(tests PRIVATE include)

target_link_libraries(tests PRIVATE GTest::gtest_main SFML::Graphics)

include(GoogleTest)
gtest_discover_tests(tests)
