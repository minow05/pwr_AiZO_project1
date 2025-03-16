//
// Created by minow on 13-Mar-25.
//

#ifndef PWR_AIZO_PROJECT1_INSERTION_H
#define PWR_AIZO_PROJECT1_INSERTION_H

#include "SortingAlgorithm.h"

class Insertion : public SortingAlgorithm<Insertion> {
public:
    template<typename T>
    void sortImpl(T *arr, int size);
};



#endif //PWR_AIZO_PROJECT1_INSERTION_H
