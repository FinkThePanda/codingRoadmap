#include "merge_sort.hpp"
#include <iostream>
using namespace std;

// Funktion til at udskrive et array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Flettefunktion til Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    // Kopier data til midlertidige arrays L[] og R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0; // Initial index for første subarray
    int j = 0; // Initial index for andet subarray
    int k = left; // Initial index for det flettede array

    // Flet delene tilbage til det originale array
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Kopier resterende elementer af L[], hvis der er nogen
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Kopier resterende elementer af R[], hvis der er nogen
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;

    // Udskriv array efter fletningen
    cout << "Efter fletning: ";
    printArray(arr, right - left + 1);
}

// Implementering af Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sorter første og anden halvdel
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Flet de sorterede dele
        merge(arr, left, mid, right);
    }
}
