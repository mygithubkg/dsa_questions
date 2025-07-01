#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric> // For accumulate function

using namespace std;

class Solution {
  public:
    bool f(int n, vector<int> &arr, int sum,vector<vector<int>> dp){
        if (sum == 0 ) return true;
        
        if (n == 0) return false;
        if (dp[n][sum] != -1) return dp[n][sum];
        
        if (arr[n] > sum) return f(n-1,arr,sum,dp);
        
        bool include = f(n-1,arr,sum - arr[n],dp);
        bool exclude = f(n-1, arr, sum,dp);
        
        return dp[n][sum] = include || exclude;
        
    }
  
  
    
    bool equalPartition(vector<int>& arr) {
        // code here
            
        int sum = accumulate(arr.begin(),arr.end(),0);
        vector<vector<int>> dp(arr.size(),vector<int>(sum+1,-1));
        if (sum % 2 != 0) return false;
        
        return f(arr.size() - 1, arr, sum/2,dp);
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