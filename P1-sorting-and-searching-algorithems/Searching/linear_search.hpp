int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Returner indekset for elementet
        }
    }
    return -1; // Hvis elementet ikke findes
}
