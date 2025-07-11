#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    public:
    int minPathSumUtil(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        // Base case: if we reach the last row, return the value at that cell
        if (i == triangle.size() - 1) {
            return triangle[i][j];
        }
        
        // If already computed, return the stored value
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        // Calculate the minimum path sum for both possible paths
        int down = minPathSumUtil(i + 1, j, triangle, dp);
        int diagonal = minPathSumUtil(i + 1, j + 1, triangle, dp);
        
        // Store the result in dp array and return it
        return dp[i][j] = triangle[i][j] + min(down, diagonal);
    }
};

int main() {
    Solution sol;
    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };
    
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1)); // Initialize dp array with -1
    
    int result = sol.minPathSumUtil(0, 0, triangle, dp);
    cout << "Minimum Path Sum: " << result << endl; // Output: 11
    return 0;
}