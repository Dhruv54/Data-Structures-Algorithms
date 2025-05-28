/*
Search Insert Position
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104
*/

#include <iostream>
#include <vector>
using namespace std;

/**
 * @class Solution
 * Implements binary search to find target or its insertion index.
 */
class Solution {
public:
    /**
     * Performs binary search to find the index of the target,
     * or the index where it should be inserted in the sorted array.
     *
     * @param nums Sorted vector of integers
     * @param target Integer value to search for
     * @return Index of the target or insertion index
     */
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int mid;

        // Binary Search Loop
        while (start <= end) {
            mid = (start +end) / 2;  // Avoids overflow

            if (nums[mid] == target) {
                return mid;  // Target found
            } else if (nums[mid] > target) {
                end = mid - 1;  // Search left half
            } else {
                start = mid + 1;  // Search right half
            }
        }

        // Target not found, return the insertion point
        return start;
    }
};

int main() {
    Solution sol;
    
    // Test input
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    // Function call
    int result = sol.searchInsert(nums, target);

    // Output result
    cout << "Target position: " << result << endl;

    return 0;
}
