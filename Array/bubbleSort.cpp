#include <bits/stdc++.h>
using namespace std;

// Print array elements
void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Print vector elements
void printVector(vector<int>& nums) {
    for(auto val : nums) {
        cout << val << " ";
    }
    cout << endl;
}

// Swap two integers by reference
void swapTwoElement(int& val1, int& val2) {
    int temp = val1;
    val1 = val2;
    val2 = temp;
}

// Bubble Sort for arrays
void bubbleSort(int arr[], int size) {
    for(int i = size - 1; i >= 1; i--) {
        bool noSwap = true; // Optimization: track if any swap occurred
        for(int j = 0; j <= i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swapTwoElement(arr[j], arr[j + 1]);
                noSwap = false;
            }
        }
        if(noSwap) break; // If no swaps, array is already sorted
    }
}

// Bubble Sort for vectors
void bubbleSort(vector<int>& nums) {
    int size = nums.size();
    for(int i = size - 1; i >= 1; i--) {
        bool noSwap = true;
        for(int j = 0; j <= i - 1; j++) {
            if(nums[j] > nums[j + 1]) {
                swapTwoElement(nums[j], nums[j + 1]);
                noSwap = false;
            }
        }
        if(noSwap) break;
    }
}

// Main function to test bubble sort
int main() {
    int arr[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> nums = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    cout << "Original Array: ";
    printArray(arr, 9);
    bubbleSort(arr, 9);
    cout << "Sorted Array: ";
    printArray(arr, 9);

    cout << "\nOriginal Vector: ";
    printVector(nums);
    bubbleSort(nums);
    cout << "Sorted Vector: ";
    printVector(nums);

    return 0;
}

/*

Time Complexity
| Case         | Complexity | Notes                                                      |
| ------------ | ---------- | ---------------------------------------------------------- |
| Best Case    | O(n)       | When the array is already sorted (early exit optimization) |
| Average Case | O(n²)      | Nested loop comparisons and swaps                          |
| Worst Case   | O(n²)      | Reverse-sorted list                                        |

Space Complexity : O(1) – Bubble Sort is an in-place algorithm, requiring no extra memory allocation.

*/