#include <iostream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;


int partition(vector<int>& arr, int low, int high) {
    /// Randomly select a pivot index
    int pivotIndex = low + rand() % (high - low + 1);

    /// Swap the pivot element with the last element
    swap(arr[pivotIndex], arr[high]);

    int pivot = arr[high]; // Pivot element
    int i = low - 1;       // Index of the smaller element

    // Partitioning loop
    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // Increment index of smaller element
            swap(arr[i], arr[j]); // Swap elements at i and j
        }
    }
    swap(arr[i + 1], arr[high]); // Place the pivot element in its correct position
    return (i + 1); // Return the partitioning index
}


void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array
        int pi = partition(arr, low, high);

        // Recursively sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Seed for random number generation
    srand(time(nullptr));
    cout<<"\n--- [Randomized Quick Sort] ---"<<endl;

    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    cout << "Original array: ";
    printArray(arr);
    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
