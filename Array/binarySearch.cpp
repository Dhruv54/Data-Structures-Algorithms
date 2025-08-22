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


/*
Problem Statement
Given a sorted array of integers and a target value, determine whether the target exists in the array using Binary Search.
If the target exists, print "target found!!", otherwise print "target not found!!".

📖 Explanation of the Problem
You are given a sorted list nums.
You need to check whether a given target is present in this list.
The solution uses Binary Search (Recursive) to reduce the search space:
Compare target with the middle element.
If equal → found.
If smaller → search left half.
If larger → search right half.
Stop when low > high.
Binary Search is much faster than linear search when the array is large.

🔎 Dry Run Example
Let’s dry run your main() example:
nums = {1,2,3,4,5,6,7,8,9,10,11,12,13,14}
target = 15

low = 0, high = 13
mid = (0+13)/2 = 6 → nums[6] = 7
target (15) > 7 → search right half.

low = 7, high = 13
mid = (7+13)/2 = 10 → nums[10] = 11
target (15) > 11 → search right half.

low = 11, high = 13
mid = (11+13)/2 = 12 → nums[12] = 13
target (15) > 13 → search right half.

low = 13, high = 13
mid = (13+13)/2 = 13 → nums[13] = 14
target (15) > 14 → search right half.

low = 14, high = 13 → condition breaks.

❌ Target not found → prints "target not found!!".

⚡ Edge Cases
Empty array → [] with any target → "target not found!!".
Target at beginning → nums = [1,2,3,4], target = 1 → "target found!!".
Target at end → nums = [1,2,3,4], target = 4 → "target found!!".
Target not present but within range → nums = [1,2,3,5,6], target = 4 → "target not found!!".
Target smaller than all elements → nums = [10,20,30], target = 5 → "target not found!!".
Target larger than all elements → nums = [10,20,30], target = 40 → "target not found!!".
Single element present → nums = [7], target = 7 → "target found!!".
Single element absent → nums = [7], target = 5 → "target not found!!".

⏱ Time Complexity
Each step cuts the array in half.
Total steps ≈ log₂(N)
Time Complexity: O(log N)

💾 Space Complexity
Recursive implementation → each call adds to call stack.
Max depth = log₂(N) calls.
Space Complexity: O(log N) (recursive stack).
⚡ If iterative version was used → Space Complexity = O(1).
✅ Binary Search Explained with This Code

BS(nums, low, high, target) is the recursive function.
Base condition: if low > high → target not found.
Middle element: mid = (low+high)/2.

Compare:
If nums[mid] == target → found.
If target > nums[mid] → search right half.
Else → search left half.

This process continues until either target is found or array cannot be divided further.
*/

#include<bits/stdc++.h>
#include<vector>
using namespace std;
void printVector(vector<int>&nums)
{
    for(auto val: nums)
    {
        cout<<val<<" ";
    }
    cout<<endl;
}

bool BS(vector<int>&nums,int low, int high, int target)
{
    if(low>high)
        return false;
    int mid = (low+high)/2;
    
    if(nums[mid]==target)
        return true;
    if(target > nums[mid])
        return BS(nums,mid+1,high,target);
    return BS(nums,low,mid-1,target);
}

void Search(vector<int>&nums,int target)
{
    if(BS(nums,0,nums.size()-1,target))
    {
        cout<<"target found!!"<<endl;
    }
    else
    {
        cout<<"target not found!!"<<endl;
    }
}

int main()
{
    vector<int>nums = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,20,25};
    cout<<"Original vector : ";
    printVector(nums);
    int target = 19;
    Search(nums,target);
    return 0;
}