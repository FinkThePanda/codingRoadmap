
#include "../BubbleSort/bubble_sort.hpp"
#include "../InsertionSort/insertion_sort.hpp"
#include "../MergeSort/merge_sort.hpp"
#include "../QuickSort/quick_sort.hpp"
#include "../SelectionSort/selection_sort.hpp"
#include <iostream>
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;

// Funktion til at kopiere et array
void copyArray(int source[], int dest[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = source[i];
    }
}

// Funktion til at udskrive et array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Testfunktion til at måle tid og sammenligne algoritmer
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
    int sortedArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int reverseArray[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int randomArray[] = {45, 23, 89, 67, 12, 78, 34, 56, 90, 32};

    int smallSize = sizeof(smallArray) / sizeof(smallArray[0]);
    int sortedSize = sizeof(sortedArray) / sizeof(sortedArray[0]);
    int reverseSize = sizeof(reverseArray) / sizeof(reverseArray[0]);
    int randomSize = sizeof(randomArray) / sizeof(randomArray[0]);

    // Test med Bubble Sort
    cout << "Testing Bubble Sort:" << endl;
    testSortingAlgorithm(bubbleSort, smallArray, smallSize, "Bubble Sort");
    testSortingAlgorithm(bubbleSort, sortedArray, sortedSize, "Bubble Sort");
    testSortingAlgorithm(bubbleSort, reverseArray, reverseSize, "Bubble Sort");
    testSortingAlgorithm(bubbleSort, randomArray, randomSize, "Bubble Sort");

    // Test med Selection Sort
    cout << "\nTesting Selection Sort:" << endl;
    testSortingAlgorithm(selectionSort, smallArray, smallSize, "Selection Sort");
    testSortingAlgorithm(selectionSort, sortedArray, sortedSize, "Selection Sort");
    testSortingAlgorithm(selectionSort, reverseArray, reverseSize, "Selection Sort");
    testSortingAlgorithm(selectionSort, randomArray, randomSize, "Selection Sort");

    // Test med Merge Sort
    cout << "\nTesting Merge Sort:" << endl;
    testSortingAlgorithm(mergeSort, smallArray, smallSize, "Merge Sort");
    testSortingAlgorithm(mergeSort, sortedArray, sortedSize, "Merge Sort");
    testSortingAlgorithm(mergeSort, reverseArray, reverseSize, "Merge Sort");
    testSortingAlgorithm(mergeSort, randomArray, randomSize, "Merge Sort");

    // Test med Insertion Sort
    cout << "\nTesting Insertion Sort:" << endl;
    testSortingAlgorithm(insertionSort, smallArray, smallSize, "Insertion Sort");
    testSortingAlgorithm(insertionSort, sortedArray, sortedSize, "Insertion Sort");
    testSortingAlgorithm(insertionSort, reverseArray, reverseSize, "Insertion Sort");
    testSortingAlgorithm(insertionSort, randomArray, randomSize, "Insertion Sort");

    // Test med Quick Sort
    cout << "\nTesting Quick Sort:" << endl;
    testSortingAlgorithm(quickSort, smallArray, smallSize, "Quick Sort");
    testSortingAlgorithm(quickSort, sortedArray, sortedSize, "Quick Sort");
    testSortingAlgorithm(quickSort, reverseArray, reverseSize, "Quick Sort");
    testSortingAlgorithm(quickSort, randomArray, randomSize, "Quick Sort");

    return 0;
}
