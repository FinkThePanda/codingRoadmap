#include "quick_sort.hpp"
#include <iostream>
using namespace std;

// Funktion til at udskrive et array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Partitioneringsfunktion for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Vi bruger det sidste element som pivot
    int i = (low - 1); // Index for det mindste element

    for (int j = low; j <= high - 1; j++) {
        // Hvis nuværende element er mindre end eller lig med pivot
        if (arr[j] <= pivot) {
            i++; // Øg indeks for det mindste element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Implementering af Quick Sort med trinvis visning
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partitionér arrayet

        // Udskriv array efter hver partitionering
        cout << "Efter partitionering omkring pivot (" << arr[pi] << "): ";
        printArray(arr, high - low + 1);

        // Rekursiv sortering af delene før og efter partitioneringspunktet
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
