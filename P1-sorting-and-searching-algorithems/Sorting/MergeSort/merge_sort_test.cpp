#include "merge_sort.hpp"
#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

void copyArray(int source[], int dest[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = source[i];
    }
}

void testSortingAlgorithm(void (*sortFunc)(int[], int, int), int arr[], int size, const string& algorithmName) {
    int* testArr = new int[size];
    copyArray(arr, testArr, size);

    auto start = high_resolution_clock::now();
    sortFunc(testArr, 0, size - 1);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << algorithmName << " sorteret array på " << size << " elementer tog " << duration.count() << " microsekunder." << endl;

    delete[] testArr;
}

int main() {
    // Test arrays
    int smallArray[] = {64, 34, 25, 12, 22, 11, 90};
    int smallSize = sizeof(smallArray) / sizeof(smallArray[0]);

    // Test array med Merge Sort og trinvis visning
    cout << "Testing Merge Sort (med trinvis visning):" << endl;
    testSortingAlgorithm(mergeSort, smallArray, smallSize, "Merge Sort");

    return 0;
}
