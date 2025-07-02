/*
Problem:
Given an unsorted array of integers, find the length of the longest sequence of consecutive integers (numbers appearing in order, without gaps). The sequence does not need to be contiguous in the array but must be in sorted order.

Example 1:
Input: [102, 4, 100, 1, 101, 3, 2, 1, 1]
Output: 4
Explanation: The longest consecutive sequence is [1, 2, 3, 4].

Constraints:
The array can contain duplicates.
The array can have negative numbers.
If the array is empty, return 0.

Edge Cases
[] → Output: 0 (Empty array)
[5] → Output: 1 (Single element)
[1,1,1,1] → Output: 1 (All same)
[1,2,0,1] → Output: 3 (Unordered with duplicates)
[10,30,20] → Output: 1 (No consecutive elements)
[1,2,2,3] → Output: 3 (Duplicate in sequence)


Approach 1 — Brute Force (O(N²))
Idea: For each element, try to build the longest sequence by checking num+1, num+2 … in a nested loop.

Approach 2 — Better (Sort + O(NlogN))
Idea: Sort the array. Remove duplicates.Count longest run of consecutive numbers.

Approach 3 — Optimal (HashSet, O(N))
Idea: Insert all elements in an unordered set. For each number, check if it’s the start of a sequence (no num-1).Expand forward.

*/

#include <bits/stdc++.h>
using namespace std;

// Utility to print vector
void printVector(const vector<int>& nums) {
    for (auto val : nums)
        cout << val << " ";
    cout << endl;
}

// =================== BRUTE FORCE ===================
int longestConsecutiveBrute(vector<int> nums) {
    if (nums.empty()) return 0;

    int maxLen = 1;

    for (int i = 0; i < nums.size(); ++i) {
        int curr = nums[i];
        int len = 1;

        // Keep checking for next consecutive
        while (find(nums.begin(), nums.end(), curr + 1) != nums.end()) {
            ++curr;
            ++len;
        }

        maxLen = max(maxLen, len);
    }

    return maxLen;
}

// =================== BETTER ===================
int longestConsecutiveBetter(vector<int> nums) {
    if (nums.empty()) return 0;

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    int maxLen = 1, currLen = 1;

    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] == nums[i - 1] + 1) {
            ++currLen;
        } else {
            currLen = 1;
        }
        maxLen = max(maxLen, currLen);
    }

    return maxLen;
}

// =================== OPTIMAL ===================
int longestConsecutiveOptimal(vector<int> nums) {
    if (nums.empty()) return 0;

    unordered_set<int> s(nums.begin(), nums.end());
    int maxLen = 1;

    for (auto num : s) {
        if (s.find(num - 1) == s.end()) {
            int curr = num;
            int len = 1;

            while (s.find(curr + 1) != s.end()) {
                ++curr;
                ++len;
            }
            maxLen = max(maxLen, len);
        }
    }

    return maxLen;
}

// =================== MAIN ===================
int main() {
    vector<vector<int>> testCases = {
        {102, 4, 100, 1, 101, 3, 2, 1, 1},
        {},
        {5},
        {1, 1, 1, 1},
        {1, 2, 0, 1},
        {10, 30, 20},
        {1, 2, 2, 3}
    };

    for (auto& nums : testCases) {
        cout << "Input: ";
        printVector(nums);

        cout << "Brute Force: " << longestConsecutiveBrute(nums) << endl;
        cout << "Better: " << longestConsecutiveBetter(nums) << endl;
        cout << "Optimal: " << longestConsecutiveOptimal(nums) << endl;
        cout << "---------------------------\n";
    }

    return 0;
}

/*
| **Approach**          | **Time Complexity** | **Space Complexity** | **In-Place**                | **Notes**                                                                                             |
| --------------------- | ------------------- | -------------------- | --------------------------- | ----------------------------------------------------------------------------------------------------- |
| **Brute Force**       | O(N²)               | O(1)                 | ✅ Yes                       | For each number, repeatedly search for next; uses `find()` each time → very slow for large arrays     |
| **Better (Sorting)**  | O(N log N)          | O(1) to O(N)         | ✅ Yes (sort modifies array) | Sorts input, removes duplicates, counts consecutive runs; easy to implement                           |
| **Optimal (HashSet)** | O(N)                | O(N)                 | ❌ No                        | Uses extra `unordered_set` for O(1) lookups; only checks sequence starts → fastest for unsorted input |
*/