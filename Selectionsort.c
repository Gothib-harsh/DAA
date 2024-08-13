// Selection Sort function with a counter
int selectionSort(vector<int>& arr) {
    int n = arr.size();
    int counter = 0;
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            counter++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
    return counter;
}

// Function to compare execution time and operation count of both sorts
void compareSorts(vector<int>& arr) {
    // Copy the array for each sort to ensure both sorts are on the same data
    vector<int> arr1 = arr;
    vector<int> arr2 = arr;

    // Bubble Sort
    auto start = high_resolution_clock::now();
    int bubbleOps = bubbleSort(arr1);
    auto stop = high_resolution_clock::now();
    auto bubbleTime = duration_cast<microseconds>(stop - start);

    // Selection Sort
    start = high_resolution_clock::now();
    int selectionOps = selectionSort(arr2);
    stop = high_resolution_clock::now();
    auto selectionTime = duration_cast<microseconds>(stop - start);

    cout << "Bubble Sort Time: " << bubbleTime.count() << " microseconds, Operations: " << bubbleOps << endl;
    cout << "Selection Sort Time: " << selectionTime.count() << " microseconds, Operations: " << selectionOps << endl;
}

int main() {
    // Generate a random list of integers
    int array_size = 1000;  // Change this size for larger or smaller tests
    vector<int> random_array(array_size);

    // Fill the vector with random integers
    generate(random_array.begin(), random_array.end(), []() {
        return rand() % 10000;
    });

    // Compare the sorting algorithms
    compareSorts(random_array);

    return 0;
}
