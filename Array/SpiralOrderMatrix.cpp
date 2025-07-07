/*
Problem Statement:
Print a 2D Matrix in Spiral Order

Description:
Given a rows × cols 2D matrix, print all its elements in spiral order, starting from the top-left element and moving clockwise towards the center.

Input:
A 2D matrix of integers with dimensions rows × cols.

Output:
A 1D list of integers representing the matrix elements in spiral order.

Example:
Input:
1  2  3
4  5  6
7  8  9

Output:
1 2 3 6 9 8 7 4 5

*/

/*
How the Algorithm Works

Key Variables
top — starting row index
bottom — ending row index
left — starting column index
right — ending column index

The traversal goes in 4 directions repeatedly:
Left → Right (top row)
Top → Bottom (right column)
Right → Left (bottom row)
Bottom → Top (left column)

Each time, the respective top, bottom, left, or right bound is moved inward.
*/
#include <bits/stdc++.h>
using namespace std;

/*
------------------------------------------------
Print a 2D matrix in Spiral Order
------------------------------------------------
Time Complexity: O(N*M)
Space Complexity: O(N*M) for output array
------------------------------------------------
*/

vector<int> printArrayElementToSpiral(int (*matrix)[5], int rows, int cols) {
    vector<int> ans;

    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {

        // 1. Traverse Top Row
        for (int i = left; i <= right; i++)
            ans.push_back(matrix[top][i]);
        top++;

        // 2. Traverse Right Column
        for (int i = top; i <= bottom; i++)
            ans.push_back(matrix[i][right]);
        right--;

        // 3. Traverse Bottom Row (if still valid)
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                ans.push_back(matrix[bottom][i]);
            bottom--;
        }

        // 4. Traverse Left Column (if still valid)
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                ans.push_back(matrix[i][left]);
            left++;
        }
    }

    return ans;
}

int main() {
    const int ROWS = 5;
    const int COLS = 5;

    int matrix[ROWS][COLS];

    // Fill with sample values: (row * col)
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            matrix[i][j] = (i + 1) * (j + 1);

    // Show the matrix
    cout << "5x5 Matrix:\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }

    // Spiral traversal
    vector<int> result = printArrayElementToSpiral(matrix, ROWS, COLS);

    cout << "\nSpiral Order Output:\n";
    for (auto val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}

/*
| Method | Time     | Space                      |
| ------ | -------- | -------------------------- |
| Spiral | O(N × M) | O(N × M) for result vector |
*/