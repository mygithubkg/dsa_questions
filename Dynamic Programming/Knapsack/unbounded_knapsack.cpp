#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// User function Template for C++

class Solution {
  public:
    int f(int ind, vector<int>& val, vector<int>& wt, int capacity,vector<vector<int>> &dp){
        
        if (ind< 0 || capacity==0) return 0;
        
        if (dp[ind][capacity] != -1) return dp[ind][capacity];
        
        if (wt[ind] > capacity ){
            return f(ind-1,val, wt,capacity, dp);
            
        };
            
        
        int notpick = f(ind -1, val,wt, capacity,dp);
        int pick = val[ind] + f(ind,val,wt,capacity - wt[ind],dp);
        
        return dp[ind][capacity] = max(notpick,pick);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<vector<int>> dp(val.size(),vector<int>(capacity+1,-1));
        
        return f(val.size() -1,val,wt,capacity,dp);
    }
};

int main() {
    Solution sol;
    vector<int> val = {60, 100, 120}; // Example values
    vector<int> wt = {10, 20, 30}; // Example weights
    int capacity = 50; // Example capacity

    int result = sol.knapSack(val, wt, capacity);
    cout << "Maximum value in Knapsack = " << result << endl;

    return 0;
}