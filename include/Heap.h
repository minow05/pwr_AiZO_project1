//
// Created by minow on 13-Mar-25.
//

#ifndef PWR_AIZO_PROJECT1_HEAP_H
#define PWR_AIZO_PROJECT1_HEAP_H

#include "SortingAlgorithm.h"
#include <cmath>
#include <iostream>

class Heap : public SortingAlgorithm<Heap> {
private:
    template<typename T>
    void heapify(T *arr, int size, int level);
    template<typename T>
    void buildMaxHeap(T *arr, int size);
public:
    template<typename T>
    void sortImpl(T *arr, int size);

};

#endif //PWR_AIZO_PROJECT1_HEAP_H