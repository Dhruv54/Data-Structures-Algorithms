/*
Problem Statement
Title: Count the Number of Subarrays with Given XOR

Description:
Given an integer array nums and an integer k, find the total number of contiguous subarrays whose elements XOR to exactly k.

Input:
nums : A vector of integers.
k : The target XOR value.

Output:
Total count of contiguous subarrays whose XOR equals k.

Input: nums = [4, 2, 2, 6, 4], k = 6  
Output: 4

Explanation:
The subarrays with XOR equal to 6 are:
[4, 2], [2, 2, 6], [6], [2, 6, 4]

*/

#include <bits/stdc++.h>
using namespace std;

/*
--------------------------------------------------------
Find total number of subarrays with given XOR k.
--------------------------------------------------------
Approach:
- Use prefix XOR.
- If prefix_xor ^ k == prev_prefix_xor, it means
  the subarray between those points XORs to k.
- Use hash map to store counts of prefix_xor values.
--------------------------------------------------------
Time: O(N)
Space: O(N)
--------------------------------------------------------
*/

int findSubArray(vector<int>& nums, int k) {
    int cnt = 0;
    map<int, int> mpp;
    mpp[0] = 1;  // For subarrays starting from index 0

    int xr = 0;
    for (int i = 0; i < nums.size(); i++) {
        xr ^= nums[i];          // Running prefix XOR
        int x = xr ^ k;         // Find needed prefix XOR
        cnt += mpp[x];          // If exists, increment count
        mpp[xr]++;              // Store/update prefix XOR count
    }
    return cnt;
}

int main() {
    vector<int> nums = {4, 2, 2, 6, 4};
    int k = 6;

    cout << "Total subarrays with XOR " << k << ": " << findSubArray(nums, k) << endl;
    return 0;
}


/*

Step-by-Step Execution for {4, 2, 2, 6, 4}, k = 6

| i | nums\[i] | xr (prefix XOR) | x = xr ^ k | mpp\[x] | Count Increment | Total Count | mpp\[xr] after |
| - | -------- | --------------- | ---------- | ------- | --------------- | ----------- | -------------- |
| 0 | 4        | 4               | 2          | 0       | +0              | 0           | mpp\[4] = 1    |
| 1 | 2        | 6               | 0          | 1       | +1              | 1           | mpp\[6] = 1    |
| 2 | 2        | 4               | 2          | 0       | +0              | 1           | mpp\[4] = 2    |
| 3 | 6        | 2               | 4          | 2       | +2              | 3           | mpp\[2] = 1    |
| 4 | 4        | 6               | 0          | 1       | +1              | 4           | mpp\[6] = 2    |

Edge Cases

| Case | nums          | k     | Expected                                                         |
| ---- | ------------- | ----- | ---------------------------------------------------------------- |
| 1    | \[0, 0, 0]    | 0     | 6 (all possible subarrays have XOR 0)                            |
| 2    | \[1, 2, 3]    | 0     | 0 (no subarray XORs to 0 except if elements themselves XOR to 0) |
| 3    | \[1, 1, 1, 1] | 1     | 4                                                                |
| 4    | \[5, 5, 5]    | 5     | 3                                                                |
| 5    | \[]           | any k | 0                                                                |


Time & Space Complexity
| Method                | Time | Space |
| --------------------- | ---- | ----- |
| Prefix XOR + Hash Map | O(N) | O(N)  |

Key Idea
The XOR trick: A ^ B = C ⇒ A = B ^ C

So, prefixXOR ^ k = previousPrefixXOR

Count how many times this needed previousPrefixXOR has appeared.

*/