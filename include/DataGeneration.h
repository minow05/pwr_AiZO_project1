#ifndef PWR_AIZO_PROJECT1_DATAGENERATION_H
#define PWR_AIZO_PROJECT1_DATAGENERATION_H

#include <random>

template<typename T>
class DataGeneration {
public:
    DataGeneration() = default;
    T* generateData(int size){
        T* arr = new T[size];
        std::uniform_int_distribution<T> rand(0, size);
        for (int i = 0; i < size; ++i){
            arr[i] = rand(gen);
        }
        return arr;
    }
private:
    std::random_device rd;
    std::mt19937 gen{rd()};
};

#endif //PWR_AIZO_PROJECT1_DATAGENERATION_H