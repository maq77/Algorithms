#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Selecting the last element as the pivot
    int i = low+1; // Index of the smaller element

    for (int j = low+1; j <= high; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            swap(arr[i++], arr[j]);
        }
    }
    swap(arr[low], arr[i-1]);
    return i-1;
}



///Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        cout<<"Pivot"<<pi<<endl;
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
    vector<int> arr = { 6,10,9,12,3,4};
    int n = arr.size();

    cout << "Original array: ";
    printArray(arr);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
