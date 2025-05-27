/*
Remove Element
Easy
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

int k = removeElement(nums, val); // Calls your implementation

assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

 

Example 1:

Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).
 

Constraints:

0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100

*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * Removes all instances of `val` from the vector `nums` in-place.
     *
     * @param nums The vector of integers to modify.
     * @param val The value to remove from the vector.
     * @return The number of elements remaining in the vector after removal (i.e., elements not equal to `val`).
     *
     * Time Complexity: O(n)
     *   - Each element is visited at most once.
     * Space Complexity: O(1)
     *   - No additional memory is used; modifications are done in-place.
     */
    int removeElement(vector<int>& nums, int val) {
        int first = 0;                   // Pointer to scan from the start
        int last = nums.size() - 1;      // Pointer to scan from the end

        while (first <= last) {
            if (nums[first] == val) {
                // If the current element is the target value, swap it with the last valid element
                swap(nums[first], nums[last]);
                // Decrease last to exclude the swapped element from future checks
                last--;
                // Do not increment `first` here since the swapped element from the end may also be equal to `val`
            } else {
                // If current element is not the target value, move to the next
                first++;
            }
        }

        // `first` now represents the count of non-`val` elements
        return first;
    }
};


/*
Complexity Analysis
Metric				Value	Reason
Time Complexity		O(n)	Each element is visited at most once
Space Complexity	O(1)	In-place modification, no extra memory

*/