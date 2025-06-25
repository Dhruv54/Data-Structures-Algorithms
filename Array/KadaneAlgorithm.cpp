/*
Problem: Maximum Subarray Sum (Kadane’s Algorithm)
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum, and return its sum.

Constraints:
1.At least one element exists.
1.Can include negative numbers.

*/


/*
1. Brute-force Approach
Time Complexity: O(N²)
Space Complexity: O(1)

*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};


/*
This is Kadane's Algorithm.
2. Prefix Sum Optimization
Time Complexity: O(N)
Space Complexity: O(1)
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            maxSum = max(maxSum, sum);
            if (sum < 0) sum = 0; // reset if current sum is negative
        }
        return maxSum;
    }
};

/*
3. Extended Kadane's (Return Subarray Indices)
Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    pair<int, int> maxSubArrayWithIndices(vector<int>& nums) {
        int maxSum = nums[0], sum = nums[0];
        int start = 0, tempStart = 0, end = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (sum + nums[i] < nums[i]) {
                sum = nums[i];
                tempStart = i;
            } else {
                sum += nums[i];
            }

            if (sum > maxSum) {
                maxSum = sum;
                start = tempStart;
                end = i;
            }
        }
        cout << "Max Sum Subarray is from index " << start << " to " << end << endl;
        return {start, end};
    }
};

/*
| Approach           | Time Complexity | Space Complexity | Returns Indices? | Notes                                 |
| ------------------ | --------------- | ---------------- | ---------------- | ------------------------------------- |
| Brute-force        | O(N²)           | O(1)             | ❌                | Simple but inefficient                |
| Kadane’s Algorithm | O(N)            | O(1)             | ❌                | Most optimal for max sum              |
| Extended Kadane’s  | O(N)            | O(1)             | ✅                | Also gives subarray start & end index |

*/