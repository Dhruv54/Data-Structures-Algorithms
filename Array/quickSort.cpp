#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Prints the elements of a vector.
 * 
 * @param nums The vector to be printed.
 */
void printVector(const vector<int>& nums) {
    for (int val : nums) {
        cout << val << " ";
    }
    cout << endl;
}

/**
 * @brief Swaps two integers by reference.
 * 
 * @param val1 First integer
 * @param val2 Second integer
 */
void swapTwoElement(int& val1, int& val2) {
    int temp = val1;
    val1 = val2;
    val2 = temp;
}

/**
 * @brief Partition function for QuickSort using Lomuto Partition Scheme.
 *        Chooses the first element as pivot, and rearranges elements such that
 *        elements less than pivot are on left and greater are on right.
 * 
 * @param nums The vector of integers.
 * @param low The starting index of the subarray.
 * @param high The ending index of the subarray.
 * @return int The index position of the pivot element after partition.
 */
int findPartitionIndex(vector<int>& nums, int low, int high) {
    int pivot = nums[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && nums[i] <= pivot) {
            i++;
        }
        while (j >= low + 1 && nums[j] > pivot) {
            j--;
        }
        if (i < j) {
            swapTwoElement(nums[i], nums[j]);
        }
    }

    // Place pivot at the correct position
    swapTwoElement(nums[low], nums[j]);
    return j;
}

/**
 * @brief Recursive QuickSort function.
 * 
 * @param nums The vector to be sorted.
 * @param low The starting index of the subarray.
 * @param high The ending index of the subarray.
 */
void quickSort(vector<int>& nums, int low, int high) {
    if (low < high) {
        int pIndex = findPartitionIndex(nums, low, high);
        quickSort(nums, low, pIndex - 1);
        quickSort(nums, pIndex + 1, high);
    }
}

/**
 * @brief Main function to test QuickSort.
 * 
 * @return int Exit status.
 */
int main() {
    vector<int> nums = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    cout << "\nOriginal Vector: ";
    printVector(nums);

    // Correct size of the vector used
    quickSort(nums, 0, nums.size() - 1);

    cout << "Sorted Vector: ";
    printVector(nums);

    return 0;
}

/*

Time and Space Complexity
Complexity Type		Value
Time Complexity 	(Average Case)	O(n log n)
Time Complexity 	(Worst Case)	O(n²) when the pivot is the smallest/largest element in sorted order
Time Complexity 	(Best Case)	O(n log n)
Space Complexity	O(log n) (due to recursive call stack)

*/