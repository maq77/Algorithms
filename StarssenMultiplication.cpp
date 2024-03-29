#include <iostream>
#include <vector>
using namespace std;

// Function to multiply two matrices using divide and conquer
vector<vector<int>> matrixMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n, 0));

    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
    } else {
        int mid = n / 2;
        vector<vector<int>> A11(mid, vector<int>(mid));
        vector<vector<int>> A12(mid, vector<int>(mid));
        vector<vector<int>> A21(mid, vector<int>(mid));
        vector<vector<int>> A22(mid, vector<int>(mid));

        vector<vector<int>> B11(mid, vector<int>(mid));
        vector<vector<int>> B12(mid, vector<int>(mid));
        vector<vector<int>> B21(mid, vector<int>(mid));
        vector<vector<int>> B22(mid, vector<int>(mid));

        // Divide input matrices into quarters
        for (int i = 0; i < mid; i++) {
            for (int j = 0; j < mid; j++) {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + mid];
                A21[i][j] = A[i + mid][j];
                A22[i][j] = A[i + mid][j + mid];

                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + mid];
                B21[i][j] = B[i + mid][j];
                B22[i][j] = B[i + mid][j + mid];
            }
        }

        // Recursively multiply submatrices
        vector<vector<int>> C11 = matrixMultiply(A11, B11) + matrixMultiply(A12, B21);
        vector<vector<int>> C12 = matrixMultiply(A11, B12) + matrixMultiply(A12, B22);
        vector<vector<int>> C21 = matrixMultiply(A21, B11) + matrixMultiply(A22, B21);
        vector<vector<int>> C22 = matrixMultiply(A21, B12) + matrixMultiply(A22, B22);

        // Combine submatrices to get the result
        for (int i = 0; i < mid; i++) {
            for (int j = 0; j < mid; j++) {
                C[i][j] = C11[i][j];
                C[i][j + mid] = C12[i][j];
                C[i + mid][j] = C21[i][j];
                C[i + mid][j + mid] = C22[i][j];
            }
        }
    }

    return C;
}

// Function to print a matrix
void printMatrix(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> A = {{1, 2},
                             {3, 4}};

    vector<vector<int>> B = {{5, 6},
                             {7, 8}};

    vector<vector<int>> result = matrixMultiply(A, B);

    cout << "Result of matrix multiplication: \n";
    printMatrix(result);

    return 0;
}
