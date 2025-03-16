//
// Created by minow on 13-Mar-25.
//
#include <string>
#include <iostream>
#include <algorithm>

#ifndef PWR_AIZO_PROJECT1_SORTINGALGORITHM_H
#define PWR_AIZO_PROJECT1_SORTINGALGORITHM_H

template<class Derived>
class SortingAlgorithm {
public:

    SortingAlgorithm() = default;
    virtual ~SortingAlgorithm() = default;

    template<typename T>
    void sort(T *arr, int size) {
        static_cast<Derived*>(this)->sortImpl(arr, size);
    }
    //Curiously recurring template pattern (CRTP) because we want to inherit virtual template method

    template<typename T>
    void printArray(T *arr, int size){
        printf("Array: \n");
        for (int i = 0; i < size; ++i){
            std::cout << *(arr + i) << " ";
        }
        std::cout << std::endl;
    };

protected:

    template<typename T>
    void sortImpl(T *arr, int size){
        if (size <= 1) return;
        std::sort(arr, arr + size);
    };
};



#endif //PWR_AIZO_PROJECT1_SORTINGALGORITHM_H
