#include "selection_sort.hpp"
#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

// Funktion til at kopiere et array (bruges til at teste samme array på flere algoritmer)
void copyArray(int source[], int dest[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = source[i];
    }
}

// Funktion til at teste og måle tid for Selection Sort
void testSortingAlgorithm(void (*sortFunc)(int[], int), int arr[], int size, const string& algorithmName) {
    int* testArr = new int[size];
    copyArray(arr, testArr, size);

    auto start = high_resolution_clock::now();
    sortFunc(testArr, size);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    cout << algorithmName << " sorteret array på " << size << " elementer tog " << duration.count() << " microsekunder." << endl;

    delete[] testArr;
}

int main() {
    // Test arrays
    int smallArray[] = {64, 34, 25, 12, 22, 11, 90};
    int sortedArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int reverseArray[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int randomArray[] = {45, 23, 89, 67, 12, 78, 34, 56, 90, 32};

    int smallSize = sizeof(smallArray) / sizeof(smallArray[0]);
    int sortedSize = sizeof(sortedArray) / sizeof(sortedArray[0]);
    int reverseSize = sizeof(reverseArray) / sizeof(reverseArray[0]);
    int randomSize = sizeof(randomArray) / sizeof(randomArray[0]);

    // Test arrays med Selection Sort
    cout << "Testing Selection Sort:" << endl;
    testSortingAlgorithm(selectionSort, smallArray, smallSize, "Selection Sort");
    testSortingAlgorithm(selectionSort, sortedArray, sortedSize, "Selection Sort");
    testSortingAlgorithm(selectionSort, reverseArray, reverseSize, "Selection Sort");
    testSortingAlgorithm(selectionSort, randomArray, randomSize, "Selection Sort");

    // Auxiliary Space for Selection Sort er O(1)
    cout << "Selection Sort Auxiliary Space: O(1)" << endl;

    return 0;
}
