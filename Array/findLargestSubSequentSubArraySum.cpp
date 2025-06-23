#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& nums) 
{
    for (int val : nums) 
    {
        cout << val << " ";
    }
    cout << endl;
}

int findLargestSubSequentSubArraySum(vector<int>& nums, int k)
{
    int left = 0, sum = 0, maxLen = 0;

    for (int right = 0; right < nums.size(); right++)
    {
        sum += nums[right];

        while (sum > k && left <= right)
        {
            sum -= nums[left];
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() 
{
    vector<int> nums = {1, 2, 3, 2, 1, 1, 1, 1, 3, 3};
    int k = 6;
    cout << "\nOriginal Vector: ";
    printVector(nums);
    
    cout << "Max Length of Subarray with sum ≤ " << k << ": ";
    cout << findLargestSubSequentSubArraySum(nums, k) << endl;
    
    return 0;
}

/*
Time and Space Complexity:
Time Complexity: O(n) – each element is visited at most twice (right and left).

Space Complexity: O(1) – only variables used, no extra space proportional to input size.
*/