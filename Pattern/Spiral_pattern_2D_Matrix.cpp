#include <iostream>
using namespace std;

const int nrc = 10;

// Function to print the entire 2D array
void printArray(int arr[nrc][nrc], int n) {
    cout << "Full Array:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to print one layer (circle) of the matrix in spiral order
void printSpiral(int arr[nrc][nrc], int n, int layer) {
    int start = layer;
    int end = n - 1 - layer;

    // Top row: left to right
    for (int j = start; j <= end; j++) {
        cout << arr[start][j] << "\t";
    }

    // Right column: top to bottom
    for (int i = start + 1; i <= end; i++) {
        cout << arr[i][end] << "\t";
    }

    // Bottom row: right to left (only if different from top)
    if (start != end) {
        for (int j = end - 1; j >= start; j--) {
            cout << arr[end][j] << "\t";
        }

        // Left column: bottom to top (only if different from right)
        for (int i = end - 1; i > start; i--) {
            cout << arr[i][start] << "\t";
        }
    }
}

int main() {
    int arr[nrc][nrc];

    // Initialize array with values from 0 to nrc*nrc - 1
    for (int i = 0; i < nrc; i++) {
        for (int j = 0; j < nrc; j++) {
            arr[i][j] = i * nrc + j;
        }
    }

    // Print the entire array
    printArray(arr, nrc);

    // Print spiral for each layer
    cout << "Spiral Order by Layers:\n";
    for (int layer = 0; layer <= nrc / 2; layer++) {
        printSpiral(arr, nrc, layer);
    }

    cout << endl;
    return 0;
}
