#include "selection_sort.hpp"
#include <iostream>
using namespace std;

// Funktion til at udskrive et array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Implementering af Selection Sort med trinvis visning
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Find det mindste element i den usorterede del
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Byt det fundne mindste element med det første element
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;

        // Udskriv array efter hvert sorteringstrin
        cout << "Efter trin " << i + 1 << ": ";
        printArray(arr, n);
    }
}
