/*
Problem: Best Time to Buy and Sell Stock
Given an array nums where each element is the price of a stock on that day, find the maximum profit you can achieve by buying and selling the stock exactly once.

Constraints:
You must buy before you sell.

The array contains at least one price.

*/

/*
1. Brute-force Approach
Time Complexity: O(N²)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int maxProfit = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                maxProfit = max(maxProfit, nums[j] - nums[i]);
            }
        }
        return maxProfit;
    }
};

/*
2. Optimized Approach (Greedy with Tracking Minimum Value)
Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int maxProfit = 0;
        int minVal = nums[0]; // Assume the first element is the minimum initially
        
        for (int i = 1; i < nums.size(); i++) {
            // Calculate potential profit if sold on the current day
            int profit = nums[i] - minVal;

            // Update the maximum profit if the current profit is higher
            maxProfit = max(maxProfit, profit);

            // Update the minimum price encountered so far
            minVal = min(minVal, nums[i]);
        }
        return maxProfit;
    }
};

/*
3. Optimized Approach with Explanation (Tracking Both Buy and Sell Days)
Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int maxProfit = 0;
        int minVal = nums[0];
        int buyDay = 0, sellDay = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < minVal) {
                minVal = nums[i]; // Update the minimum value (buy day)
                buyDay = i;
            }

            int profit = nums[i] - minVal;
            if (profit > maxProfit) {
                maxProfit = profit;  // Update max profit
                sellDay = i;  // Update the sell day
            }
        }
        cout << "Buy on day " << buyDay << " and sell on day " << sellDay << endl;
        return maxProfit;
    }
};

/*
| Approach               | Time Complexity | Space Complexity | Returns Indices? | Notes                                |
| ---------------------- | --------------- | ---------------- | ---------------- | ------------------------------------ |
| Brute-force            | O(N²)           | O(1)             | ❌                | Simple but inefficient               |
| Optimized (Greedy)     | O(N)            | O(1)             | ❌                | Most efficient for maximizing profit |
| Optimized with Indices | O(N)            | O(1)             | ✅                | Tracks the buy/sell days too         |
*/