#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>   

using namespace std;


// Time Complexity - O(N*W) where N is the number of items and W is the maximum weight capacity of the knapsack
// Space Complexity - O(N*W) for the DP table
// If we have used Recursion then Time complexity would be O(2^N) and Space Complexity would be O(N) for the recursion stack

    
class Solution {
  public:
  
    int f(int i, int W, vector<int> & val, vector<int> &wt,vector<vector<int>> &dp){
        if (i< 0 || W==0) return 0;
        
        // We have 2-D DP because if i = 3 but it can have differe W may be at 10 and 7 as we can pick or notpick so bith should be treated differently and not same 
        if (dp[i][W] != -1) return dp[i][W];
        
        int ans = 0;
        
        // If weight of the current item is greater than W, we cannot include it
        // So we will not pick it and move to the next item 
        if (wt[i] > W ){
            return f(i-1, W,val, wt, dp);
            
        };
        
        // If we can include the current item, we have two choices:
        // 1. Pick the item and reduce the weight W by wt[i]
        // 2. Do not pick the item and move to the next item
        // We take the maximum of both choices
        int pick = val[i] +f(i-1,W - wt[i],val,wt,dp);
        int notpick = f(i-1,W,val,wt,dp);
        
        return dp[i][W] = max(pick,notpick);
    }   
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size() -1;
        vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
        int ans = f(n,W,val,wt,dp);
        
        
        return ans;
    }
};

int main() {
    Solution sol;
    int W = 50; // Maximum weight capacity of the knapsack
    vector<int> val = {0, 60, 100, 120}; // Item values (1-indexed)
    vector<int> wt = {0, 10, 20, 30}; // Item weights (1-indexed)

    int result = sol.knapsack(W, val, wt);
    
    cout << "Maximum value in Knapsack = " << result << endl;
    
    return 0;
}   