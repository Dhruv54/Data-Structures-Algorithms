/*
1. Two Sum

Given an array of integers nums and an integer target, return the indices of the two numbers such that they add up to target.

Constraints:
- Exactly one solution exists.
- You may not use the same element twice.
- Return the answer in any order.

Examples:
Input: nums = [2,7,11,15], target = 9     → Output: [0,1]
Input: nums = [3,2,4], target = 6         → Output: [1,2]
Input: nums = [3,3], target = 6           → Output: [0,1]
*/


// -----------------------------
// 1. Brute-force Method
// Time Complexity: O(N^2)
// Space Complexity: O(1)
// -----------------------------
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> targetIndex;
            int sum = 0;
    
            // Try every pair to check if sum equals target
            for (int i = 0; i < nums.size(); i++) {
                for (int j = i + 1; j < nums.size(); j++) {
                    sum = nums[i] + nums[j];
                    if (target == sum) {
                        targetIndex.push_back(i);
                        targetIndex.push_back(j);
                        return targetIndex;
                    }
                }
            }
    
            return targetIndex; // Return empty if no solution found (shouldn't happen per constraints)
        }
    };
    
    
    // -----------------------------
    // 2. Two Pointer Technique (Only works when we want actual numbers, not indices)
    // Time Complexity: O(N log N) [due to sorting]
    // Space Complexity: O(1)
    // Note: This is NOT valid for index return, since sorting changes the original order.
    // -----------------------------
    class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end()); // Sorting is required for two-pointer approach
            vector<int> sumsIndex;
    
            int i = 0;
            int j = nums.size() - 1;
    
            // Move pointers based on comparison
            while (i < j) {
                int sum = nums[i] + nums[j];
    
                if (sum > target) {
                    j--;
                } else if (sum < target) {
                    i++;
                } else {
                    // Found the pair
                    sumsIndex.push_back(nums[i]);
                    sumsIndex.push_back(nums[j]);
                    return sumsIndex;
                }
            }
    
            return sumsIndex; // Return empty if not found
        }
    };
    
    
    // -----------------------------
    // 3. Optimal Method using Hash Map
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    // -----------------------------
    class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            std::unordered_map<int, int> umapIndex; // Maps number to its index
            std::vector<int> targetIndex;
    
            for (int i = 0; i < nums.size(); i++) {
                int complement = target - nums[i];
    
                // Check if the complement already exists in the map
                if (umapIndex.find(complement) != umapIndex.end()) {
                    targetIndex.push_back(umapIndex[complement]);
                    targetIndex.push_back(i);
                    return targetIndex;
                }
    
                // Store the index of the current number
                umapIndex[nums[i]] = i;
            }
    
            return targetIndex; // Should not reach here as per problem guarantee
        }
    };

/*
Summary:

| Approach    | Time Complexity | Space Complexity | Works for Indices? | Notes                                    |
| ----------- | --------------- | ---------------- | ------------------ | ---------------------------------------- |
| Brute-force | O(N²)           | O(1)             | Yes                | Simple but inefficient                   |
| Two-pointer | O(N log N)      | O(1)             | No                 | Only gives numbers, not original indices |
| Hash map    | O(N)            | O(N)             | Yes                | Most efficient for this problem          |

*/