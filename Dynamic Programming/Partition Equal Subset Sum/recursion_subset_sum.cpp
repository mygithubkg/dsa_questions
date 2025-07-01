#include<iostream>
#include<vector>
#include<algorithm> 
#include<numeric> // For accumulate function

using namespace std;


class Solution {
  public:
    bool f(int n, vector<int> &arr, int sum){
        // if the sum is 0, we can always form a subset with sum 0 (empty subset)
        if (sum == 0 ) return true;
        
        if (n == 0) return false;
        
        // if the current element is greater than the sum, we cannot include it
        // so we skip it and check the rest of the elements
        if (arr[n] > sum) return f(n-1,arr,sum);
        
        // we have two choices: include the current element or exclude it
        // include the current element and reduce the sum by the value of the current element
        // exclude the current element and keep the sum as it is
        // if either choice leads to a valid subset, we return true
        bool include = f(n-1,arr,sum - arr[n]);
        bool exclude = f(n-1, arr, sum);
        
        return include || exclude;
        
    }
  
  
    
    bool equalPartition(vector<int>& arr) {
        // code here
            
        int sum = accumulate(arr.begin(),arr.end(),0);

        if (sum % 2 != 0) return false;
        
        return f(arr.size() - 1, arr, sum/2);
    }
};


int main() {
    Solution sol;
    vector<int> arr = {1, 5, 11, 5}; // Example input array

    if (sol.equalPartition(arr)) {
        cout << "The array can be partitioned into two subsets with equal sum." << endl;
    } else {
        cout << "The array cannot be partitioned into two subsets with equal sum." << endl;
    }

    return 0;
}