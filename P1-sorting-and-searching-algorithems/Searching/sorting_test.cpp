#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Linear Search
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

// Binary Search
int binarySearch(int arr[], int low, int high, int target) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] > target)
            return binarySearch(arr, low, mid - 1, target);

        return binarySearch(arr, mid + 1, high, target);
    }

    return -1;
}

// Testfunktion for søgealgoritmer
void testSearchAlgorithm(int (*searchFunc)(int[], int, int), int arr[], int n, int target, const string& algorithmName) {
    auto start = high_resolution_clock::now();
    int result = searchFunc(arr, n, target);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    if (result != -1) {
        cout << algorithmName << " fandt elementet ved index " << result << " på " << duration.count() << " microsekunder." << endl;
    } else {
        cout << algorithmName << " kunne ikke finde elementet, tog " << duration.count() << " microsekunder." << endl;
    }
}

// Overload for Binary Search
void testSearchAlgorithm(int (*searchFunc)(int[], int, int, int), int arr[], int n, int target, const string& algorithmName) {
    auto start = high_resolution_clock::now();
    int result = searchFunc(arr, 0, n - 1, target);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);
    if (result != -1) {
        cout << algorithmName << " fandt elementet ved index " << result << " på " << duration.count() << " microsekunder." << endl;
    } else {
        cout << algorithmName << " kunne ikke finde elementet, tog " << duration.count() << " microsekunder." << endl;
    }
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    cout << "Testing Linear Search:" << endl;
    testSearchAlgorithm(linearSearch, arr, n, target, "Linear Search");

    cout << "\nTesting Binary Search:" << endl;
    testSearchAlgorithm(binarySearch, arr, n, target, "Binary Search");

    return 0;
}
