#include "Algorithms/Quick.h"
#include "Algorithms/Shell.h"
#include "Algorithms/Insertion.h"
#include "Algorithms/Heap.h"
#include "UI/UserInterface.h"
#include "DataGeneration.h"
#include <iostream>
#include <memory>
#include <variant>

#define SIZE 1000 // 200

int getAlgorithmChoice(){
    std::cout << "Choose which sorting algorithm you want to use:\n";
    std::cout << "1. Quick Sort\n";
    std::cout << "2. Shell Sort\n";
    std::cout << "3. Insertion Sort\n";
    std::cout << "4. Heap Sort\n";
    int choice;
    std::cin >> choice;
    return choice;
}

bool getSlowModeChoice(){
    std::cout << "Do you want to slow down the sorting process and see it working? (y/n)\n"
                 "WARNING: SORTING TIME RESULT WON'T BE ACCURATE!\n";
    char choice;
    std::cin >> choice;
    return choice == 'y';
}

int getTypeOfArrayChoice(){
    std::cout << "Choose which type of array you want to sort:\n";
    std::cout << "1. Random\n";
    std::cout << "2. Sorted\n";
    std::cout << "3. Reverse Sorted\n";
    int choice;
    std::cin >> choice;
    return choice;
}

int getSizeOfArrayChoice(){
    std::cout << "Choose the size of the array you want to sort:\n(It should be between 1000 and 100000)\n";
    int choice;
    std::cin >> choice;
    return choice;
}

int getTypeOfDataChoice(){
    std::cout << "Choose which type of data you want to sort:\n";
    std::cout << "1. Integers\n";
    std::cout << "2. Floats\n";
    int choice;
    std::cin >> choice;
    return choice;
}

int main() {
    DataGeneration<int> dataGeneration(1000);
    std::cout << "breakpoint 1\n";
    Insertion insertion = Insertion(false);
    std::cout << "breakpoint 2\n";
    int *arr = dataGeneration.getArray("random");
    std::cout << "breakpoint 3\n";
    insertion.sort(arr, 1000);
    std::cout << "breakpoint 4\n";
    insertion.printArray(arr, 1000);
    std::cout << "breakpoint 5\n";
    insertion.printTime(1000);
    std::cout << "breakpoint 6\n";
    dataGeneration.saveArray(arr, "random");
    std::cout << "breakpoint 7\n";
//    UserInterface ui;
//    std::cout << "Welcome to the sorting visualizer!\n";
//    bool chosen = false;
//    while(!chosen) {
//        switch (getAlgorithmChoice()) {
//            case 1: {
//                Quick quick = Quick(false);
//                chosen = true;
//                break;
//            }
//            case 2: {
//                Shell shell = Shell(false);
//                chosen = true;
//                break;
//            }
//            case 3: {
//                Insertion insertion = Insertion(false);
//                chosen = true;
//                break;
//            }
//            case 4: {
//                Heap heap = Heap(false);
//                std::cout << "Invalid choice, try again.\n";
//                chosen = true;
//                break;
//            } default: {
//                std::cout << "Invalid choice, try again.\n";
//            }
//        }
//    }
    return 0;
}