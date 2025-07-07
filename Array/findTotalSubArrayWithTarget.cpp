/*
Problem Statement
Count the Number of Subarrays with a Given Sum

Description:
Given an integer array nums and an integer target, count the total number of contiguous subarrays whose sum is equal to target.

Input:
An array nums of integers, which may include positive, negative, and zero values.
An integer target representing the desired subarray sum.

Output:
Return the total count of all possible contiguous subarrays whose elements sum up to target.

Example:
Input: nums = [1, 2, 3, -3, 1, 1, 1, 4, 2, -3], target = 3  
Output: 6

Explanation: The subarrays with sum equal to 3 are:
[1, 2], [3], [3, -3, 1, 1, 1], [-3, 1, 1, 1, 4, 2, -3], [1, 1, 1], [1, 1, 1, 4, 2, -3]

Constraints:
The length of nums is up to 10⁵ for the optimal solution.
The elements of nums can be positive, negative, or zero.

*/

#include <bits/stdc++.h>
using namespace std;

// Utility: Print Vector
void printVector(vector<int>& nums) {
    for (auto val : nums)
        cout << val << " ";
    cout << endl;
}

/*
-------------------------------------------
Brute Force Approach:
-------------------------------------------
- Idea: Generate all possible subarrays using 3 nested loops.
- For each subarray, calculate sum.
- If sum == target, increment count.

Time Complexity: O(N^3)
Space Complexity: O(1)
*/
int findSubArrayBrute(vector<int>& nums, int target) {
    int n = nums.size();
    int iCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += nums[k];
            }
            if (sum == target)
                iCount++;
        }
    }
    return iCount;
}

/*
-------------------------------------------
Better Approach:
-------------------------------------------
- Idea: Remove innermost loop by keeping a running sum.
- For each starting index, keep adding elements ahead.

Time Complexity: O(N^2)
Space Complexity: O(1)
*/
int findSubArrayBetter(vector<int>& nums, int target) {
    int n = nums.size();
    int iCount = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            if (sum == target)
                iCount++;
        }
    }
    return iCount;
}

/*
-------------------------------------------
Optimal Approach:
-------------------------------------------
- Idea: Use Prefix Sum + HashMap.
- Track counts of prefix sums.
- If prefixSum - target exists in map, add its count.

Time Complexity: O(N)
Space Complexity: O(N)
*/
int findSubArrayOptimal(vector<int>& nums, int target) {
    map<int, int> hashMap;
    hashMap[0] = 1;
    int prefixSum = 0;
    int iCount = 0;
    for (int i = 0; i < nums.size(); i++) {
        prefixSum += nums[i];
        int removeVal = prefixSum - target;
        iCount += hashMap[removeVal];
        hashMap[prefixSum] += 1;
    }
    return iCount;
}

/*
-------------------------------------------
Run Automated Test Cases
-------------------------------------------
*/
void runTestCases() {
    vector<pair<vector<int>, int>> testCases = {
        {{1, 2, 3}, 3},                     // Simple case
        {{1, 1, 1}, 2},                     // Repeated same numbers
        {{1, 2, 1, 2, 1}, 3},               // Multiple overlapping
        {{-1, -1, 1}, 0},                   // Negative numbers
        {{3, 4, 7, 2, -3, 1, 4, 2}, 7},     // Mix of +ve/-ve
        {{1}, 1},                           // Single element equal target
        {{1}, 2},                           // Single element not equal target
        {{0, 0, 0, 0}, 0},                  // All zeros
        {{1000000, -1000000}, 0},           // Large pos/neg cancel out
        {{}, 0}                             // Empty array
    };

    cout << "---------------------------\n";
    cout << " Running 10 Automated Tests \n";
    cout << "---------------------------\n";

    for (int i = 0; i < testCases.size(); ++i) {
        vector<int> nums = testCases[i].first;
        int target = testCases[i].second;

        int resultBrute = findSubArrayBrute(nums, target);
        int resultBetter = findSubArrayBetter(nums, target);
        int resultOptimal = findSubArrayOptimal(nums, target);

        cout << "Test #" << i + 1 << " | Target: " << target << " | Array: ";
        printVector(nums);
        cout << "Brute: " << resultBrute << ", Better: " << resultBetter
             << ", Optimal: " << resultOptimal << "\n\n";
    }
}

int main() {
    vector<int> nums = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    int iTarget = 3;

    cout << "---------------------------------\n";
    cout << "Given Array: ";
    printVector(nums);

    cout << "---------------------------------\n";
    cout << "Target Sum: " << iTarget << endl;

    int resultBrute = findSubArrayBrute(nums, iTarget);
    int resultBetter = findSubArrayBetter(nums, iTarget);
    int resultOptimal = findSubArrayOptimal(nums, iTarget);

    cout << "---------------------------------\n";
    cout << "Brute Force Result: " << resultBrute << endl;
    cout << "Better Approach Result: " << resultBetter << endl;
    cout << "Optimal Approach Result: " << resultOptimal << endl;

    cout << "---------------------------------\n";
    runTestCases();

    return 0;
}

/*
| Method      | Time Complexity | Space Complexity | Notes                            |
| ----------- | --------------- | ---------------- | -------------------------------- |
| Brute Force | O(N³)           | O(1)             | Triple nested loops              |
| Better      | O(N²)           | O(1)             | Double nested loops, running sum |
| Optimal     | O(N)            | O(N)             | Prefix sum with hash map         |

*/

/*

| i | nums\[i] | prefixSum | removeVal (prefixSum - target) | hashMap before update                        | hashMap\[removeVal] | New iCount | hashMap after update                              |
| - | -------- | --------- | ------------------------------ | -------------------------------------------- | ------------------- | ---------- | ------------------------------------------------- |
| 0 | 1        | 1         | -2                             | `{0:1}`                                      | 0                   | 0          | `{0:1, 1:1}`                                      |
| 1 | 2        | 3         | 0                              | `{0:1, 1:1}`                                 | 1                   | 1          | `{0:1, 1:1, 3:1}`                                 |
| 2 | 3        | 6         | 3                              | `{0:1, 1:1, 3:1}`                            | 1                   | 2          | `{0:1, 1:1, 3:1, 6:1}`                            |
| 3 | -3       | 3         | 0                              | `{0:1, 1:1, 3:1, 6:1}`                       | 1                   | 3          | `{0:1, 1:1, 3:2, 6:1}`                            |
| 4 | 1        | 4         | 1                              | `{0:1, 1:1, 3:2, 6:1}`                       | 1                   | 4          | `{0:1, 1:1, 3:2, 4:1, 6:1}`                       |
| 5 | 1        | 5         | 2                              | `{0:1, 1:1, 3:2, 4:1, 6:1}`                  | 0                   | 4          | `{0:1, 1:1, 3:2, 4:1, 5:1, 6:1}`                  |
| 6 | 1        | 6         | 3                              | `{0:1, 1:1, 3:2, 4:1, 5:1, 6:1}`             | 2                   | 6          | `{0:1, 1:1, 3:2, 4:1, 5:1, 6:2}`                  |
| 7 | 4        | 10        | 7                              | `{0:1, 1:1, 3:2, 4:1, 5:1, 6:2}`             | 0                   | 6          | `{0:1, 1:1, 3:2, 4:1, 5:1, 6:2, 10:1}`            |
| 8 | 2        | 12        | 9                              | `{0:1, 1:1, 3:2, 4:1, 5:1, 6:2, 10:1}`       | 0                   | 6          | `{0:1, 1:1, 3:2, 4:1, 5:1, 6:2, 10:1, 12:1}`      |
| 9 | -3       | 9         | 6                              | `{0:1, 1:1, 3:2, 4:1, 5:1, 6:2, 10:1, 12:1}` | 2                   | 8          | `{0:1, 1:1, 3:2, 4:1, 5:1, 6:2, 9:1, 10:1, 12:1}` |

*/