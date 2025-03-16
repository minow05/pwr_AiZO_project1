//
// Created by minow on 13-Mar-25.
//

#include "../include/Insertion.h"

template<typename T>
void Insertion::sortImpl(T *arr, int size) {
    if (size <= 1) return;
    for (int counter = 1; counter < size; counter++) {
        int temp = arr[counter];
        int i = counter - 1;
        while (i >= 0 && arr[i] > temp) {
            std::swap(arr[i + 1], arr[i]);
            i--;
        }
        arr[i + 1] = temp;
    }
}

template void Insertion::sortImpl(float *arr, int size);
template void Insertion::sortImpl(int *arr, int size);
