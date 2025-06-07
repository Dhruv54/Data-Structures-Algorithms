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

// Insertion Sort for arrays
void insertionSort(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = i; j > 0; j--) {
            if(arr[j - 1] > arr[j]) {
                swapTwoElement(arr[j - 1], arr[j]);
            }
        }
    }
}

// Insertion Sort for vectors
void insertionSort(vector<int>& nums) {
    int size = nums.size();
    for(int i = 0; i < size; i++) {
        for(int j = i; j > 0; j--) {
            if(nums[j - 1] > nums[j]) {
                swapTwoElement(nums[j - 1], nums[j]);
            }
        }
    }
}

// Main function to test insertion sort
int main() {
    int arr[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> nums = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    cout << "Original Array: ";
    printArray(arr, 9);
    insertionSort(arr, 9);
    cout << "Sorted Array: ";
    printArray(arr, 9);

    cout << "\nOriginal Vector: ";
    printVector(nums);
    insertionSort(nums);
    cout << "Sorted Vector: ";
    printVector(nums);

    return 0;
}

/*

Time Complexity
| Case         | Complexity | Notes                            |
| ------------ | ---------- | -------------------------------- |
| Best Case    | O(n)       | When the array is already sorted |
| Average Case | O(n²)      | Elements are in random order     |
| Worst Case   | O(n²)      | Reverse-sorted list              |

Space Complexity : O(1) – Insertion Sort is an in-place algorithm. It doesn’t use any extra memory.

*/