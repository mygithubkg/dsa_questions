#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
  public:
  
    int f(int i , int j, vector<vector<int>> & grid, vector<vector<int>> &dp){
        // Reached the end (as we are starting from destination so 0,0 is end)
        if (i == 0 && j == 0 && grid[i][j] != 1) return 1;
        // Out of grid not possible 
        if ( i<0 || j <0) return 0;
        
        // 1 means path not possible 
        if (grid[i][j] == 1) return 0;
        
        // if already in dp
        if (dp[i][j] != -1) return dp[i][j]; 
        
        // will move up or left 
        int up = f(i-1,j, grid,dp);
        int left = f(i,j-1,grid,dp);
        
        return dp[i][j] = up + left;
        
        
    }
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        int ans = f(n-1,m-1,grid,dp);
        return ans;
        
    }
    
};
int main(){
    Solution sol;
    vector<vector<int>> grid = {{0,0,0},{0,1,0},{0,0,0}};
    cout << sol.uniquePaths(grid) << endl; // Output: 2
    return 0;
}