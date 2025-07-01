/*
Problem: Leaders in an Array

A leader is an element that is strictly greater than all elements to its right.
The rightmost element is always a leader (since there are no elements to its right).

*/
/*
Brute-force
Time Complexity: O(N²)
Space Complexity: O(1)
For each element, check all elements to its right.

*/

class Solution {
public:
    vector<int> findLeadersBruteForce(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            bool isLeader = true;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] >= nums[i]) {
                    isLeader = false;
                    break;
                }
            }
            if (isLeader) result.push_back(nums[i]);
        }

        return result;
    }
};


/*
Optimal: Right to Left Scan
Time Complexity: O(N)
Space Complexity: O(1) + O(K) for output

*/

vector<int> findLeaders(vector<int>& nums) {
    vector<int> result;
    int iMax = INT_MIN;

    for (int i = nums.size() - 1; i >= 0; i--) {
        if (nums[i] > iMax) {
            result.push_back(nums[i]);
            iMax = nums[i];
        }
    }

    // To get leaders in original order:
    reverse(result.begin(), result.end());

    return result;
}

/*
| Approach              | Time Complexity | Space Complexity | Preserves Order | Notes                            |
| --------------------- | --------------- | ---------------- | --------------- | -------------------------------- |
| Brute-force           | O(N²)           | O(1)             | ✅               | Inefficient, but simple to grasp |
| Optimal Right-to-Left | O(N)            | O(1) + O(K)      | ✅               | Fastest, minimal extra space     |

*/