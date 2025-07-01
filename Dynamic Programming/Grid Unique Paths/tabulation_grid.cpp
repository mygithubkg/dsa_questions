#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution{
    public:
    int uniquePaths(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // all dp elements are initialized to 0 by default
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        // if the starting cell is blocked, return 0
        if (grid[0][0] == 1 || grid[n-1][m-1] == 1) return 0;
        
        // base case: starting point
        dp[0][0] = 1;
        
        // fill the first row
        for (int j = 1; j < m; j++) {
            if (grid[0][j] == 0) {
                dp[0][j] = dp[0][j-1];
            }
        }
        
        // fill the first column
        for (int i = 1; i < n; i++) {
            if (grid[i][0] == 0) {
                dp[i][0] = dp[i-1][0];
            }
        }
        
        // fill the rest of the dp table
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (grid[i][j] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        
        return dp[n-1][m-1];
    }
};
// We can optimize the space complexity to O(m) by using a single row array instead of a 2D array, but for clarity, we will keep the 2D array in this implementation.
// the new code will be with space optimization is 
// #include<iostream>
// #include<vector> 
// #include<algorithm>
// using namespace std;
//
// class Solution{
//     public:
//     int uniquePaths(vector<vector<int>> &grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//

        // all dp elements are initialized to 0 by default
//         vector<int> dp(m, 0);
        
//         // if the starting cell is blocked, return 0
//         if (grid[0][0] == 1 || grid[n-1][m-1] == 1) return 0;
        
//         // base case: starting point
//         dp[0] = 1;
        
//         // fill the first row
//         for (int j = 1; j < m; j++) {
//             if (grid[0][j] == 0) {
//                 dp[j] = dp[j-1];
//             } else {
//                 dp[j] = 0; // blocked cell
//             }
//         }
        
//         // fill the rest of the dp table
//         for (int i = 1; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (grid[i][j] == 0) {
//                     int up = (i > 0) ? dp[j] : 0;
//                     int left = (j > 0) ? dp[j-1] : 0;
//                     dp[j] = up + left;
//                 } else {
//                     dp[j] = 0; // blocked cell
//                 }
//             }
//         }
        
//         return dp[m-1];
//     }
// };

int main() {
    Solution sol;
    vector<vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << sol.uniquePaths(grid) << endl; // Output: 2
    return 0;
}