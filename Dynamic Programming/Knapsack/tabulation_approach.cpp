#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

class Solution {
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int w = 0; w <= W; ++w) {
                if (wt[i - 1] <= w) {
                    int pick = val[i - 1] + dp[i - 1][w - wt[i - 1]];
                    int notPick = dp[i - 1][w];
                    dp[i][w] = max(pick, notPick);
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }
        return dp[n][W];
    }
};
int main() {
    Solution sol;
    int W = 50; // Maximum weight capacity of the knapsack
    vector<int> val = {60, 100, 120}; // Item values
    vector<int> wt = {10, 20, 30}; // Item weights

    int result = sol.knapsack(W, val, wt);
    
    cout << "Maximum value in Knapsack = " << result << endl;
    
    return 0;
}