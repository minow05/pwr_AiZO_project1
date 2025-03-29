//
// Created by minow on 13-Mar-25.
//
#include "../include/Heap.h"
#include <iostream>


template<typename T>
void Heap::heapify(T *arr, int size, int level) {
    int max = level;
    int left = 2 * level + 1;
    int right = 2 * level + 2;

    if (left < size && arr[left] > arr[max]) {
        max = left;
    }
    if (right < size && arr[right] > arr[max]) {
        max = right;
    }

    if (max != level) {
        std::swap(arr[level], arr[max]);
        heapify(arr, size, max);
    }
}

template<typename T>
void Heap::buildMaxHeap(T *arr, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }
}


template<typename T>
void Heap::sortImpl(T *arr, int size) {
    if (size <= 1) return;
    buildMaxHeap(arr, size);  // convert the array into a max heap

    for (int i = size - 1; i > 0; i--) {
        delayFunction();
        std::swap(arr[0], arr[i]);  // move the largest element to the end
        heapify(arr, i, 0);
    }
}

template void Heap::sortImpl(float *arr, int size);
template void Heap::sortImpl(int *arr, int size);