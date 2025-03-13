//
// Created by minow on 13-Mar-25.
//
#include <gtest/gtest.h>
#include "../include/SortingAlgorithm.h"
TEST(PrintArrayTest, CheckOutput) {
    // Define the array
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;

    // Create an instance of SortingAlgorithm
    SortingAlgorithm sortingAlgorithm;

    // Redirect cout to a stringstream to capture the output
    std::stringstream output;
    std::streambuf* originalCoutStream = std::cout.rdbuf(output.rdbuf());

    // Call the function that prints the array
    sortingAlgorithm.printArray(&arr, size);

    // Check the output
    std::string expectedOutput = "Sorted Algorithim:\n1 2 3 4 5";
    EXPECT_EQ(output.str(), expectedOutput);

    // Restore original cout
    std::cout.rdbuf(originalCoutStream);
}