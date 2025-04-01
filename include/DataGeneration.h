#ifndef PWR_AIZO_PROJECT1_DATAGENERATION_H
#define PWR_AIZO_PROJECT1_DATAGENERATION_H

#include <random>
#include "Algorithms/SortingAlgorithm.h"
#include "Algorithms/Heap.h"
#include "Algorithms/Insertion.h"
#include "Algorithms/Quick.h"
#include "Algorithms/Shell.h"

template<typename T>
class DataGeneration {
public:
    DataGeneration() = default;
    T* generateRandom(int size){
        T* arr = new T[size];
        std::uniform_real_distribution<T> rand(0, size);
        for (int i = 0; i < size; ++i){
            arr[i] = rand(gen);
        }
        return arr;
    }

    T* generateSorted(int size){
        T* arr = new T[size];
        for (int i = 0; i < size; ++i){
            arr[i] = i;
        }
        return arr;
    }

    T* generateReverseSorted(int size){
        T* arr = new T[size];
        for (int i = 0; i < size; ++i){
            arr[i] = size - i;
        }
        return arr;
    }

    Insertion insertion = Insertion(false);
    Heap heap = Heap(false);
    Quick quick = Quick(false);
    Shell shell = Shell(false);


private:
    std::random_device rd;
    std::mt19937 gen{rd()};
};



#endif //PWR_AIZO_PROJECT1_DATAGENERATION_H