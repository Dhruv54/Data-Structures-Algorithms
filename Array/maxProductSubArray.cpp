/*
Problem Statement
Find Maximum Product Subarray

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest product and return its product.


Approach
We use two traversals:
Prefix traversal (from left to right)
Suffix traversal (from right to left)
At every index:
We multiply the current number with the ongoing prefix and suffix.
If any becomes zero, reset to 1.
Keep updating the maximum product encountered.
This handles negative numbers effectively, since the maximum product might be from a suffix that includes even negative values.

Edge Test Cases:
| Test Case | Input                 | Expected Output | Reason                              |
| --------- | --------------------- | --------------- | ----------------------------------- |
| 1         | `{1, 2, 3, 4}`        | `24`            | All positive → whole array          |
| 2         | `{-1, -2, -3, -4}`    | `24`            | Even number of negatives            |
| 3         | `{0, -1, 0, -3, -10}` | `30`            | Ignore zero resets, pick `{-3,-10}` |
| 4         | `{-2}`                | `-2`            | Single negative element             |
| 5         | `{-1, -2, -3, 0}`     | `6`             | Use `{-1, -2, -3}` and ignore zero  |


Time Complexity: O(n)
Space Complexity: O(1)

*/

int findMaxProductSubArray(vector<int>& nums)
{
    int ans = INT_MIN;         // Stores final max product
    int n = nums.size();       
    int prefix = 1;            // Tracks prefix product
    int suffix = 1;            // Tracks suffix product

    for(int i = 0; i < n; i++)
    {
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;

        prefix *= nums[i];               // Left to right
        suffix *= nums[n - i - 1];       // Right to left

        ans = max(ans, max(prefix, suffix));
    }

    return ans;
}
