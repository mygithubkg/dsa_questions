#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
  public:
    int f(int ind, int target, vector<int> &coins,vector<vector<int>> &dp){
        // Base Case 
        if (dp[ind][target] != -1) return dp[ind][target];
        
        if (ind == 0){
            if (target % coins[0] == 0){
                return 1;
            }else{
                return 0;
            }
        }
        int nottaken = 0 + f(ind - 1, target,coins,dp);
        int taken = 0;
        if (coins[ind] <= target){
            // 1 to count ways 
            taken = f(ind,target - coins[ind],coins,dp);
        }
        
        return dp[ind][target] = taken + nottaken;
    }
    int count(vector<int>& coins, int sum) {
        vector<vector<int>> dp(coins.size(),vector<int>(sum+1,-1));
        return f(coins.size()-1,sum,coins,dp);
    }
};

int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5}; // Example input coins
    int sum = 5; // Example target sum

    int result = sol.count(coins, sum);
    cout << "Number of ways to make the sum " << sum << " with given coins: " << result << endl;

    return 0;
}       