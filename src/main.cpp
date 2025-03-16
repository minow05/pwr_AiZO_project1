//
// Created by minow on 13-Mar-25.
//
#include "../include/Quick.h"
#include "../include/Shell.h"
#include "../include/Insertion.h"
#include "../include/Heap.h"
#include <iostream>

int main(){

    int arr[] = {100, 7, 8, 9, 1, 5};
    int arr2[] = {100, 7, 8, 9, 1, 5};
    float arrFloat[] = {0.13f, 12.14f, 10.8129f, 1.0f, 2, 7.69f};
    int arrOne[] = {2};
    Heap heap;
    Insertion insertion;
//    insertion.sort(arr, 6);
//    insertion.printArray(arr, 6);
    Quick quick;
    Shell shell;
    shell.sort(arr, 6);
    shell.printArray(arr, 6);
    shell.sort(arrFloat, 6);
    shell.printArray(arrFloat, 6);
    insertion.sort(arr2, 6);
    insertion.printArray(arr2, 6);
//    quick.setPivotMode(1, 0, 5);
//    heap.sort(arrFloat, 6);
//    heap.printArray(arrFloat, 6);
//    quick.sort(arrFloat, 6);
//    quick.printArray(arrFloat, 6);

    return 0;
}

