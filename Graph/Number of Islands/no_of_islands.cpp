#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

class Solution {
    void dfs (vector<vector<bool>> &vis, int row, int col,vector<vector<char>>& grid){
        vis[row][col] = true;
        
        vector<int> cr = {-1,-1,0,1,1,1,0,-1};
        vector<int> cc = {0,1,1,1,0,-1,-1,-1};
        
        for (int i =0; i <8; i++){
            int nr = row + cr[i];
            int nc = col + cc[i];
            if (nr >=0 && nr<vis.size()&& nc>=0 && nc<vis[0].size() && !vis[nr][nc] && grid[nr][nc] == 'L'){
                dfs(vis,nr,nc,grid);
            }
        }
    }
  
    
    public:
        
        int countIslands(vector<vector<char>>& grid) {
        // Code here
        int row = grid.size();
        int col = grid[0].size();
        
        vector<vector<bool>> vis(row,vector<bool>(col,false));
        
        int count = 0;
        
        for (int i= 0; i < row; i++){
            for (int j = 0 ; j <col; j++){
                if (grid[i][j] == 'L' && !vis[i][j]){
                    dfs(vis,i,j,grid);
                    count++;
                }
                
            }
        }
        
        return count;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> grid = {
        {'L', 'L', 'W', 'W'},
        {'L', 'W', 'W', 'L'},
        {'W', 'L', 'L', 'L'},
        {'W', 'W', 'L', 'W'}
    };
    
    int result = sol.countIslands(grid);
    cout << "Number of islands: " << result << endl; // Output: 3
    
    return 0;
}