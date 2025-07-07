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

// Selection Sort for arrays
void selectionSort(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        int minIndex = i;
        for(int j = i; j < size; j++) {
            if(arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        swapTwoElement(arr[i], arr[minIndex]);
    }
}

// Selection Sort for vectors
void selectionSort(vector<int>& nums) {
    int size = nums.size();
    for(int i = 0; i < size; i++) {
        int minIndex = i;
        for(int j = i; j < size; j++) {
            if(nums[minIndex] > nums[j]) {
                minIndex = j;
            }
        }
        swapTwoElement(nums[i], nums[minIndex]);
    }
}

// Main function to test selection sort
int main() {
    int arr[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> nums = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    cout << "Original Array: ";
    printArray(arr, 9);
    selectionSort(arr, 9);
    cout << "Sorted Array: ";
    printArray(arr, 9);

    cout << "\nOriginal Vector: ";
    printVector(nums);
    selectionSort(nums);
    cout << "Sorted Vector: ";
    printVector(nums);

    return 0;
}

/*
Time Complexity

| Case         | Complexity |
| ------------ | ---------- |
| Best Case    | O(n²)      |
| Average Case | O(n²)      |
| Worst Case   | O(n²)      |

Space Complexity : O(1) Selection Sort is an in-place algorithm (no extra space used).

*/