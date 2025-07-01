#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

// Frog Jump problem using dynamic programming
// Time Complexity - O(n) and Space Complexity - O(n) for dp array

class Solution {
  public:
  
    int f(int n, vector<int> &height, vector<int> &dp){
        if (n==0) return 0;
        
        if (dp[n] != -1) return dp[n];
        int left = f(n-1, height,dp) + abs(height[n] - height[n-1]);
        int right = INT_MAX;
        
        if (n > 1) right  = f(n-2, height,dp) + abs(height[n] - height[n-2]);
        
        return dp[n] =  min(left,right);
    }
  
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size() - 1;
        vector<int> dp(n+1,-1);
        int ans = f(n, height,dp);
        
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> height = {10, 30, 40, 20, 50}; // Example heights
    int result = sol.minCost(height);
    
    cout << "Minimum cost to reach the top: " << result << endl;
    
    return 0;
}