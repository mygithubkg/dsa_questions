#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Question says - 
// Given an array arr[], find the sum of all the subarrays of the given array.

// Note: It is guaranteed that the total sum will fit within a 32-bit integer range.

// Examples:

// Input: arr[] = [1, 2, 3] 
// Output: 20
// Explanation: All subarray sums are: [1] = 1, [2] = 2, [3] = 3, [1, 2] = 3, [2, 3] = 5, [1, 2, 3] = 6. Thus total sum is 1 + 2 + 3 + 3 + 5 + 6 = 20.
// Input: arr[] = [1, 3]
// Output: 8
// Explanation: All subarray sums are: [1] = 1, [3] = 3, [1, 3] = 4. Thus total sum is 1 + 3 + 4 = 8.
// Constraints :
// 1 ≤ arr.size() ≤ 105
// 0 ≤ arr[i] ≤ 104

// Expected Complexities
// Time Complexity: O(n)
// Auxiliary Space: O(1)


// Possible three Approaches 



// Basic
// class Solution {
//   public:
//     int subarraySum(vector<int>& arr) {
//         // code here
//         int total_sum = 0;
//         for (int k =0 ; k <arr.size(); k++){
//             for(int i = k; i <arr.size(); i++){
//                 for (int j = i; j >=k; j--){
//                     total_sum += arr[j];
//                 }
//         }
        
//         }
        
//         return total_sum;
//     }
// };

// O[n^2]
// class Solution {
//   public:
//     int subarraySum(vector<int>& arr) {
//         // code here
//         int total_sum = 0;
//         for (int k =0 ; k <arr.size(); k++){
//             int currsum = 0;
//                 for (int j = k; j <arr.size(); j--){
//                     currsum += arr[j];
//                     total_sum += currsum;
//                 }
//         }
        
        
//         return total_sum;
//     }
// };

// Element Contribution Method

class Solution{
    public:
    int subarraySum(vector<int> &arr){
        int totalsum = 0;
        int n = arr.size();
        for(int i = 0; i<n; i++){
            totalsum += arr[i]*(n-i)*(i+1);
        }
        return totalsum;
    }
};

int main(){
    Solution sol;
    vector<int> arr1 = {1, 2, 3}; // Example 1
    vector<int> arr2 = {1, 3};    // Example 2

    int result1 = sol.subarraySum(arr1);
    cout << "Total sum of subarrays in first case: " << result1 << endl;

    int result2 = sol.subarraySum(arr2);
    cout << "Total sum of subarrays in second case: " << result2 << endl;

    return 0; 
}
