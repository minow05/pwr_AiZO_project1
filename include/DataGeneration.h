#ifndef PWR_AIZO_PROJECT1_DATAGENERATION_H
#define PWR_AIZO_PROJECT1_DATAGENERATION_H

#include <fstream>
#include "Algorithms/SortingAlgorithm.h"
#include "Algorithms/Heap.h"
#include "Algorithms/Insertion.h"
#include "Algorithms/Quick.h"
#include "Algorithms/Shell.h"

template<typename T>
class DataGeneration {
public:

    DataGeneration(int size) : size(size){
        generateRandom();
        generateSorted();
        generateReverseSorted();
    };

    ~DataGeneration(){
//        delete[] readFromFile("random");
//        delete[] readFromFile("sorted");
//        delete[] readFromFile("reverseSorted");
    };

    T* getArray(const std::string name){
        readFromFile(name);
    }

    void saveArray(T* arr, std::string name){
        writeToFile(arr, name);
    }

private:

    int size = 0;

    T* generateRandom() {
        T* arr = new T[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = rand() % size;
        }
        writeToFile(arr, "random");
        return arr;
    }

    T* generateSorted() {
        T* arr = new T[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = i;
        }
        writeToFile(arr, "sorted");
        return arr;
    }

    T* generateReverseSorted() {
        T* arr = new T[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = size - i;
        }
        writeToFile(arr, "reverseSorted");
        return arr;
    }

    T* readFromFile(const std::string& filename) {
        std::ifstream inFile(filename + ".txt");
        if (!inFile) {
            std::cerr << "Error: Could not open file " << filename << ".txt for reading.\n";
            size = 0;
            return nullptr;
        }

        std::vector<T> tempData;
        T value;
        while (inFile >> value) {
            tempData.push_back(value);
        }

        size = static_cast<int>(tempData.size());
        T* arr = new T[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = tempData[i];
        }

        return arr;
    }

    void writeToFile(T *arr, const std::string &filename) {
        std::ofstream outFile(filename + ".txt");
        if (!outFile) {
            std::cerr << "Error: Unable to open file for writing.\n";
            return;
        }

        for (int i = 0; i < size; ++i) {
            outFile << arr[i] << "\n";
        }

        outFile.close();
    }

};



#endif //PWR_AIZO_PROJECT1_DATAGENERATION_H