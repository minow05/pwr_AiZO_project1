//
// Created by minow on 13-Mar-25.
//
#include "../include/Shell.h"
template<typename T>
void Shell::sortImpl(T *arr, int size){
    if (size <= 1) return;
    for (int gap = size / 2; gap > 0; gap /= 2){
        for (int i = gap; i < size; i++){
            T temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp){
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}
template void Shell::sortImpl(float *arr, int size);
template void Shell::sortImpl(int *arr,int size);