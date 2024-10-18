int binarySearch(int arr[], int low, int high, int target) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        // Hvis elementet er på midten
        if (arr[mid] == target)
            return mid;

        // Hvis elementet er mindre end midten, søg i venstre del
        if (arr[mid] > target)
            return binarySearch(arr, low, mid - 1, target);

        // Ellers søg i højre del
        return binarySearch(arr, mid + 1, high, target);
    }

    return -1; // Hvis elementet ikke findes
}
