#include "Algorithms/Quick.h"
#include "Algorithms/Shell.h"
#include "Algorithms/Insertion.h"
#include "Algorithms/Heap.h"
#include "UI/UserInterface.h"
#include "DataGeneration.h"
#include <iostream>
#include <memory>
#include <variant>

int main() {
//    DataGeneration<int> dataGeneration(800000);
//    Quick quick = Quick(false);
//    int* arr = dataGeneration.getArray("random");
//    quick.sort(arr, 800000);
//    dataGeneration.saveArray(arr, "800k_Quick");
//    UserInterface ui;
    Quick quick = Quick(false);
    DataGeneration<int> dataGen200ki(200000);
    int *arr = dataGen200ki.getArray("random");
//    quick.sort(arr, 200000);
    arr = dataGen200ki.getArray("sorted");
    quick.sort(arr, 200000);
    arr = dataGen200ki.getArray("reverseSorted");
    quick.sort(arr, 200000);
    DataGeneration<float> dataGen200kf(200000);
    float *arrf = dataGen200kf.getArray("random");
    quick.sort(arrf, 200000);
    arrf = dataGen200kf.getArray("sorted");
    quick.sort(arrf, 200000);
    arrf = dataGen200kf.getArray("reverseSorted");
    quick.sort(arrf, 200000);
    DataGeneration<int> dataGen100ki(100000);
    arr = dataGen100ki.getArray("random");
    quick.sort(arr, 100000);
    arr = dataGen100ki.getArray("sorted");
    quick.sort(arr, 100000);
    arr = dataGen100ki.getArray("reverseSorted");
    quick.sort(arr, 100000);
    DataGeneration<float> dataGen100kf(100000);
    arrf = dataGen100kf.getArray("random");
    quick.sort(arrf, 100000);
    arrf = dataGen100kf.getArray("sorted");
    quick.sort(arrf, 100000);
    arrf = dataGen100kf.getArray("reverseSorted");
    quick.sort(arrf, 100000);
    DataGeneration<int> dataGen50ki(50000);
    arr = dataGen50ki.getArray("random");
    quick.sort(arr, 50000);
    arr = dataGen50ki.getArray("sorted");
    quick.sort(arr, 50000);
    arr = dataGen50ki.getArray("reverseSorted");
    quick.sort(arr, 50000);
    DataGeneration<float> dataGen50kf(50000);
    arrf = dataGen50kf.getArray("random");
    quick.sort(arrf, 50000);
    arrf = dataGen50kf.getArray("sorted");
    quick.sort(arrf, 50000);
    arrf = dataGen50kf.getArray("reverseSorted");
    quick.sort(arrf, 50000);

//    UserInterface ui;

    return 0;
}