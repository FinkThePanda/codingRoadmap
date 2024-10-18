#include "insertion_sort.hpp"
#include <iostream>
using namespace std;

// Funktion til at udskrive et array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Implementering af Insertion Sort med trinvis visning
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Flyt elementer, der er større end key, én plads til højre
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        // Udskriv array efter hvert trin
        cout << "Efter trin " << i << ": ";
        printArray(arr, n);
    }
}
