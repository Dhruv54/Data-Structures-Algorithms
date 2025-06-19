#include <bits/stdc++.h>
using namespace std;

// ---------------------------- Utility Functions ----------------------------

// Print contents of array
void printArray(int arr[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Print contents of vector
void printVector(const vector<int>& nums) {
    cout << "Vector: ";
    for (auto val : nums)
        cout << val << " ";
    cout << endl;
}

// ------------------------ Brute Force Approach -----------------------------
/*
Approach:
Check for every number from 1 to N if it's present in the input.
Time Complexity: O(N^2)
Space Complexity: O(1)
*/

// Array version
int findMissingBrute(int arr[], int n) {
    for (int i = 1; i <= n; i++) {
        bool found = false;
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] == i) {
                found = true;
                break;
            }
        }
        if (!found)
            return i;
    }
    return 0;
}

// Vector version
int findMissingBrute(const vector<int>& nums, int n) {
    for (int i = 1; i <= n; i++) {
        bool found = false;
        for (int num : nums) {
            if (num == i) {
                found = true;
                break;
            }
        }
        if (!found)
            return i;
    }
    return 0;
}

// ------------------------ Better Approach (Hashing) ------------------------
/*
Approach:
Use an extra array to store count/frequency.
Time Complexity: O(N)
Space Complexity: O(N)
*/

// Array version
int findMissingBetter(int arr[], int n) {
    vector<int> hash(n + 1, 0);
    for (int i = 0; i < n - 1; i++)
        hash[arr[i]]++;

    for (int i = 1; i <= n; i++) {
        if (hash[i] == 0)
            return i;
    }
    return 0;
}

// Vector version
int findMissingBetter(const vector<int>& nums, int n) {
    vector<int> hash(n + 1, 0);
    for (int num : nums)
        hash[num]++;

    for (int i = 1; i <= n; i++) {
        if (hash[i] == 0)
            return i;
    }
    return 0;
}

// ---------------------- Optimal Approach (Sum Formula) ---------------------
/*
Approach:
Use sum of first N natural numbers and subtract the actual sum.
Time Complexity: O(N)
Space Complexity: O(1)
*/

// Array version
int findMissingOptimal(int arr[], int n) {
    int expectedSum = n * (n + 1) / 2;
    int actualSum = accumulate(arr, arr + n - 1, 0);
    return expectedSum - actualSum;
}

// Vector version
int findMissingOptimal(const vector<int>& nums, int n) {
    int expectedSum = n * (n + 1) / 2;
    int actualSum = accumulate(nums.begin(), nums.end(), 0);
    return expectedSum - actualSum;
}

// ------------------------------ Main Function ------------------------------
int main() {
    // Input: array of size n-1 with 1 number missing from 1 to n
    int arr[] = {1, 2, 3, 4, 5, 6, 8, 9}; // missing 7
    int n = 9;

    vector<int> nums = {1, 2, 3, 4, 5, 6, 8, 9};

    printArray(arr, n - 1);
    printVector(nums);

    cout << "\n--- Brute Force ---" << endl;
    cout << "Missing (Array):  " << findMissingBrute(arr, n) << endl;
    cout << "Missing (Vector): " << findMissingBrute(nums, n) << endl;

    cout << "\n--- Better (Hashing) ---" << endl;
    cout << "Missing (Array):  " << findMissingBetter(arr, n) << endl;
    cout << "Missing (Vector): " << findMissingBetter(nums, n) << endl;

    cout << "\n--- Optimal (Sum Formula) ---" << endl;
    cout << "Missing (Array):  " << findMissingOptimal(arr, n) << endl;
    cout << "Missing (Vector): " << findMissingOptimal(nums, n) << endl;

    return 0;
}


/*

| Approach         | Time Complexity | Space Complexity |
| ---------------- | --------------- | ---------------- |
| Brute Force      | O(N²)           | O(1)             |
| Better (Hashing) | O(N)            | O(N)             |
| Optimal (Sum)    | O(N)            | O(1)             |

Input: [1, 2, 3, 4, 5, 6, 8, 9]
Output: 7

*/