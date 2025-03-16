//
// Created by minow on 14-Mar-25.
//
#include <gtest/gtest.h>
#include <shldisp.h>
#include "../include/Heap.h"
#include "../include/Quick.h"
#include "../include/Insertion.h"
#include "../include/Shell.h"
#include "../include/SortingAlgorithm.h"

TEST(HeapSortTest, TestSizeOneArray) {
    int arr[] = {1};
    Heap heap;
    heap.sort(arr, 1);
    EXPECT_EQ(arr[0], 1);
}
TEST(QuickSortTest, TestSizeOneArray) {
    int arr[] = {1};
    Quick quick;
    quick.sort(arr, 1);
    EXPECT_EQ(arr[0], 1);
}
TEST(ShellSortTest, TestSizeOneArray) {
    int arr[] = {1};
    Shell shell;
    shell.sort(arr, 1);
    EXPECT_EQ(arr[0], 1);
}
TEST(InsertionSortTest, TestSizeOneArray) {
    int arr[] = {1};
    Insertion insertion;
    insertion.sort(arr, 1);
    EXPECT_EQ(arr[0], 1);
}