/*
Merge Sorted Array

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
 

Constraints:
nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109
 

Follow up: Can you come up with an algorithm that runs in O(m + n) time?
*/

#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Merges two sorted integer arrays nums1 and nums2 into nums1 as one sorted array.
 *
 * nums1 has a size of m + n, with the first m elements initialized and the last n elements set to 0.
 * nums2 has exactly n initialized elements.
 *
 * The function modifies nums1 in-place to contain the merged sorted array.
 *
 * @param nums1 The first sorted array, with extra space at the end to accommodate nums2.
 * @param m The number of initialized elements in nums1.
 * @param nums2 The second sorted array.
 * @param n The number of initialized elements in nums2.
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;            // Pointer to last element in nums1 (initialized portion)
        int j = n - 1;            // Pointer to last element in nums2
        int iIndex = m + n - 1;   // Pointer to last index in nums1 (total length)

        // Merge from the end to the beginning
        while (i >= 0 && j >= 0) {
            if (nums2[j] >= nums1[i]) {
                nums1[iIndex] = nums2[j];
                j--;
            } else {
                nums1[iIndex] = nums1[i];
                i--;
            }
            iIndex--;
        }

        // If any elements left in nums2, copy them
        while (j >= 0) {
            nums1[iIndex] = nums2[j];
            j--;
            iIndex--;
        }
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    solution.merge(nums1, m, nums2, n);

    cout << "Merged array: ";
    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}


/*
Time and Space Complexity
Time Complexity: O(m + n)

We iterate through all elements of both arrays once.
Each comparison and copy operation takes constant time.

Space Complexity: O(1)

The algorithm works in-place, meaning no extra space is used apart from a few integer variables (i, j, iIndex).
The result is stored directly in nums1.

*/