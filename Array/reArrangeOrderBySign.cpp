/*
Problem: Rearrange Array by Sign Alternately
Given an array nums of positive and negative integers (equal number of each), rearrange the elements so that:

They alternate by sign

The first element is positive

The relative order of elements from original groups (positive/negative) is preserved

Constraints:
Equal number of positive and negative elements

Output must be in alternating sign order: [+, -, +, -, ...]

Example:
Input: [-2, 5, 6, 7, -5, -9]
Output: [5, -2, 6, -5, 7, -9]
*/

/*
1. Brute-force Approach (with extra vectors)
Time Complexity: O(N)
Space Complexity: O(N)

*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive, negative, result;

        for (int num : nums) {
            if (num >= 0)
                positive.push_back(num);
            else
                negative.push_back(num);
        }

        for (int i = 0; i < nums.size() / 2; i++) {
            result.push_back(positive[i]);
            result.push_back(negative[i]);
        }

        return result;
    }
};

/*
2. In-Place Rearrangement Using Two Pointers (Advanced)
Time Complexity: O(N)
Space Complexity: O(1)
Only possible if we don’t need to preserve original order
*/

class Solution {
public:
    void rearrangeArrayInPlace(vector<int>& nums) {
        int n = nums.size();
        int posIndex = 0, negIndex = 1;

        vector<int> temp(nums); // Copy for rearranging

        for (int i = 0; i < n; i++) {
            if (temp[i] >= 0) {
                nums[posIndex] = temp[i];
                posIndex += 2;
            } else {
                nums[negIndex] = temp[i];
                negIndex += 2;
            }
        }
    }
};

/*
3. General Case: Handle Unequal Counts
Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive, negative, result;

        // Separate positives and negatives
        for (int num : nums) {
            if (num >= 0)
                positive.push_back(num);
            else
                negative.push_back(num);
        }

        int i = 0, j = 0;
        // Alternate as long as both lists have elements
        while (i < positive.size() && j < negative.size()) {
            result.push_back(positive[i++]);
            result.push_back(negative[j++]);
        }

        // Append remaining positives
        while (i < positive.size()) {
            result.push_back(positive[i++]);
        }

        // Append remaining negatives
        while (j < negative.size()) {
            result.push_back(negative[j++]);
        }

        return result;
    }
};

/*
| Approach                          | Time Complexity | Space Complexity | Supports Unequal?  | Preserves Order   | Notes                                  |
| --------------------------------- | --------------- | ---------------- | -----------------  | ---------------   | -------------------------------------- |
| Brute-force (equal only)          | O(N)            | O(N)             | ❌                 | ✅               | Simple and clean for equal count       |
| In-place two-pointer (no order)   | O(N)            | O(1)\*           | ❌                 | ❌               | Efficient but doesn’t preserve order   |
| Unequal counts (general case)     | O(N)            | O(N)             | ✅                 | ✅               | Handles all cases correctly with order |

*/