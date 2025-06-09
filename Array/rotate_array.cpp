#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Rotates the given array to the right by k steps using reversal algorithm.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
class Solution {
public:
    // Swap two integers by reference
    void swapTwoElement(int& val1, int& val2) {
        int temp = val1;
        val1 = val2;
        val2 = temp;
    }

    // Reverse elements from start to end indices in the array
    void reverseArray(vector<int>& nums, int start, int end) {
        while (start < end) {
            swapTwoElement(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    // Rotate array to the right by k positions
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // Handle cases where k > n

        if (k == 0) return; // No rotation needed

        reverseArray(nums, 0, n - 1);       // Reverse the whole array
        reverseArray(nums, 0, k - 1);       // Reverse first k elements
        reverseArray(nums, k, n - 1);       // Reverse remaining elements
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    solution.rotate(nums, k);

    cout << "K-Rotated array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}


/*
Time & Space Complexity
Time Complexity: O(n)
Each element is swapped at most once in each of the three reversals.

Space Complexity: O(1)
All operations are done in-place, using constant extra space.
*/