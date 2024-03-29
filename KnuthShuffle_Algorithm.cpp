#include <iostream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

void knuthShuffle(int arr[],int size) {
    srand(time(nullptr));
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(arr[i], arr[j]);
    }
}

void printArray(const int arr[],int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Original array: ";
    printArray(arr,9);

    knuthShuffle(arr,9);

    cout << "Shuffled array: ";
    printArray(arr,9);

    return 0;
}
