#include <bits/stdc++.h>
using namespace std;

// Print vector elements
void printVector(vector<int>& nums) {
    for(auto val : nums) {
        cout << val << " ";
    }
    cout << endl;
}

// Merge two sorted halves
void merge(vector<int>& nums, int low, int mid, int high) {
    int left = low;
    int right = mid + 1;
    vector<int> temp;

    // Compare elements from both halves and merge
    while(left <= mid && right <= high) {
        if(nums[left] > nums[right]) {
            temp.push_back(nums[right++]);
        } else {
            temp.push_back(nums[left++]);
        }
    }

    // Append remaining elements
    while(left <= mid) temp.push_back(nums[left++]);
    while(right <= high) temp.push_back(nums[right++]);

    // Copy sorted temp array to original array
    for(int i = low; i <= high; i++) {
        nums[i] = temp[i - low];
    }
}

// Recursive Merge Sort
void mergeSort(vector<int>& nums, int low, int high) {
    if(low >= high) return;

    int mid = (low + high) / 2;
    mergeSort(nums, low, mid);
    mergeSort(nums, mid + 1, high);
    merge(nums, low, mid, high);
}

// Merge Sort wrapper for ease of use
void mergeSort(vector<int>& nums) {
    if(nums.empty()) return;
    mergeSort(nums, 0, nums.size() - 1);
}

// Main function to test Merge Sort
int main() {
    vector<int> nums = {9, 8, 7, 6, 5, 5, 4, 3, 2, 1, 4, 5};

    cout << "\nOriginal Vector: ";
    printVector(nums);

    mergeSort(nums);

    cout << "Sorted Vector: ";
    printVector(nums);

    return 0;
}

/*

Time Complexity
| Case         | Complexity | Description                      |
| ------------ | ---------- | -------------------------------- |
| Best Case    | O(n log n) | Efficient for all types of data  |
| Average Case | O(n log n) | Balanced divide & merge steps    |
| Worst Case   | O(n log n) | Even if data is in reverse order |

Space Complexity : O(n) – Merge Sort requires additional space for temporary arrays during the merge process.

*/