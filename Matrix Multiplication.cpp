#include <iostream>
#include <vector>
#define MAX 100

using namespace std;

// Function to recursively multiply two matrices
void multiplyMatrixRec(int r1, int c1, int a[][MAX], int r2, int c2, int b[][MAX], int c[][MAX]) {
    static int i = 0, j = 0, k = 0;

    // If all rows have been traversed
    if (i >= r1)
        return;

    if (j < c2) {
        if (k < c1) {
            c[i][j] += a[i][k] * b[k][j];
            k++;
            multiplyMatrixRec(r1, c1, a, r2, c2, b, c);
        }

        k = 0;
        j++;
        multiplyMatrixRec(r1, c1, a, r2, c2, b, c);
    }

    j = 0;
    i++;
    multiplyMatrixRec(r1, c1, a, r2, c2, b, c);
}

// Function to multiply two matrices A[][] and B[][]
void multiplyMatrix(int r1, int c1, int a[][MAX], int r2, int c2, int b[][MAX]) {
    if (c1 != r2) {
        cout << "Matrix multiplication not possible!" << endl;
        return;
    }

    int c[MAX][MAX] = {0};

    multiplyMatrixRec(r1, c1, a, r2, c2, b, c);

    // Print the result
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int c1, r1, c2, r2;
    cout << "Matrix 1" << endl;
    cout << "Enter Row: ";
    cin >> r1;
    cout << "\nEnter Column: ";
    cin >> c1;
    int a[MAX][MAX] = {0};
    cout << "Matrix 2" << endl;
    cout << "Enter Row: ";
    cin >> r2;
    cout << "\nEnter Column: ";
    cin >> c2;
    int b[MAX][MAX] = {0};

    // Storing elements of first matrix.
    cout << endl << "Enter elements of Matrix 1:" << endl;
    for (int i = 0; i < r1; ++i)
        for (int j = 0; j < c1; ++j) {
            cout << "Enter element a" << i + 1 << j + 1 << " : ";
            cin >> a[i][j];
        }

    // Storing elements of second matrix.
    cout << endl << "Enter elements of Matrix 2:" << endl;
    for (int i = 0; i < r2; ++i)
        for (int j = 0; j < c2; ++j) {
            cout << "Enter element b" << i + 1 << j + 1 << " : ";
            cin >> b[i][j];
        }

    multiplyMatrix(r1, c1, a, r2, c2, b);

    return 0;
}
