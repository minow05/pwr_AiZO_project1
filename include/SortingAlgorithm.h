//
// Created by minow on 13-Mar-25.
//
#include <string>
#ifndef PWR_AIZO_PROJECT1_SORTINGALGORITHM_H
#define PWR_AIZO_PROJECT1_SORTINGALGORITHM_H


class SortingAlgorithm {
public:
    SortingAlgorithm() = default;
    virtual ~SortingAlgorithm() = default;

    template<typename T>
    void sort(T* arr, int n);

    template<typename T>
    void printArray(T* arr, int n);
};


#endif //PWR_AIZO_PROJECT1_SORTINGALGORITHM_H
