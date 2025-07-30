// You are given a circular array arr[] of integers, find the maximum possible sum of a non-empty subarray. In a circular array, the subarray can start at the end and wrap around to the beginning. Return the maximum non-empty subarray sum, considering both non-wrapping and wrapping cases.

// Examples:

// Input: arr[] = [8, -8, 9, -9, 10, -11, 12]
// Output: 22
// Explanation: Starting from the last element of the array, i.e, 12, and moving in a circular fashion, we have max subarray as 12, 8, -8, 9, -9, 10, which gives maximum sum as 22.
// Input: arr[] = [10, -3, -4, 7, 6, 5, -4, -1]
// Output: 23
// Explanation: Maximum sum of the circular subarray is 23. The subarray is [7, 6, 5, -4, -1, 10].
// Input: arr[] = [5, -2, 3, 4]
// Output: 12
// Explanation: The circular subarray [3, 4, 5] gives the maximum sum of 12.



#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;




class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int totalSum = 0;
        int maxKadane = INT_MIN, minKadane = INT_MAX;
        int currMax = 0, currMin = 0;
    
        for (int num : arr) {
            totalSum += num;
    
            // Max subarray sum (non-wrapping)
            currMax = max(num, currMax + num);
            maxKadane = max(maxKadane, currMax);
    
            // Min subarray sum
            currMin = min(num, currMin + num);
            minKadane = min(minKadane, currMin);
        }
    
        if (maxKadane < 0) return maxKadane; // All numbers are negative
        return max(maxKadane, totalSum - minKadane);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {8, -8, 9, -9, 10, -11, 12};
    
    cout << "Maximum Circular Subarray Sum: " << sol.maxCircularSum(arr) << endl;
    
    return 0;
}