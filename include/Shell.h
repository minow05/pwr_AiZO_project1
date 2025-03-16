//
// Created by minow on 13-Mar-25.
//

#ifndef PWR_AIZO_PROJECT1_SHELL_H
#define PWR_AIZO_PROJECT1_SHELL_H

#include "SortingAlgorithm.h"

class Shell : public SortingAlgorithm<Shell> {
public:
    template<typename T>
    void sortImpl(T *arr, int size);
};

#endif //PWR_AIZO_PROJECT1_SHELL_H
