#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;

// Max path Sum in matrix using max path sum in matrix 

class Solution {
public:
    // Recursive function with memoization
    int f(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        int n = mat.size(), m = mat[0].size();

        // Boundary check
        if (j < 0 || j >= m) return 0;

        // Base case: last row
        if (i == n - 1) return mat[i][j];

        // Check memo table
        if (dp[i][j] != -1) return dp[i][j];

        // Recursive calls for down, diagonal left, and diagonal right
        int down     = f(i + 1, j, mat, dp);
        int dialeft  = f(i + 1, j - 1, mat, dp);
        int diaright = f(i + 1, j + 1, mat, dp);

        // Store result in dp table
        return dp[i][j] = mat[i][j] + max({down, dialeft, diaright});
    }

    int maxPathSumMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // Memoization table
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int res = INT_MIN;

        // Try all starting points in the top row
        for (int j = 0; j < m; ++j) {
            res = max(res, f(0, j, mat, dp));
        }
        return res;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {5, 10, 20},
        {4, 1, 2},
        {3, 6, 7}
    };
    
    int result = sol.maxPathSumMatrix(mat);
    cout << "Maximum Path Sum: " << result << endl; // Output: 37
    return 0;
}
