/*
Plus One
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.

Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Example 2:
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].
Example 3:

Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
 

Constraints:
1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain any leading 0's.

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        int i = 0;

        // Start from the last digit and move backwards
        for (i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;   // Set current digit to 0 and carry over
                carry = 1;
            } else {
                digits[i] += 1;  // No carry needed, just add 1
                carry = 0;
                break;
            }
        }

        // If carry is still 1 after the loop (e.g., 999 -> 000), insert 1 at front
        if (carry == 1) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};

// Example usage
int main() {
    vector<int> number = {9, 9, 9};  // You can change this to test different inputs
    Solution solution;
    vector<int> result = solution.plusOne(number);

    cout << "Result: ";
    for (int digit : result) {
        cout << digit << " ";
    }
    cout << endl;

    return 0;
}


/*
Time and Space Complexity:
Time Complexity: O(n) in the worst case (e.g., all 9's like [9, 9, 9]), where n is the number of digits.

Space Complexity: O(1) auxiliary space since you're modifying the vector in-place (except possibly for the insert() which may shift elements).
*/