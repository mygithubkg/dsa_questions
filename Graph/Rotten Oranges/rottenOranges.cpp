#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// We will use BFS approach here because it is level wise traversal method and will allow us to know the min time required to rot the oranges 

class Solution {
    public:
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        

        int n = mat.size();
        int m = mat[0].size();
        // Count of fresh oranges
        int freshCount = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));
        // {{r,c},t}
        queue<pair<pair<int,int>,int>> q;
        
        // Here we check were rotten oranges are initailly present and what is the count of fresh oranges 
        // Also we will mark the rotten oranges as visited in the vis matrix
        // and push them into the queue
        for (int i= 0; i<n; i++){
            for (int j = 0; j<m; j++){
                if (mat[i][j]==2){
                    vis[i][j] = 2;
                    q.push({{i,j},0});
                }
                else if (mat[i][j] == 1) {
                    freshCount++; // Count fresh oranges
                }
            }
        }
        
        // this will be used to check up right down left side of rotten oranges 
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,1,0,-1};

        // to check the time taken to rot fresh oranges 
        int tm = 0;
        
        while (!q.empty()){

            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            
            tm = max (tm,t);
            
            // checking for the 4 directions for fresh oranges near rotten oranges , pushed the new rotten oranges into the queue and marking them as visited
            // and decrementing the fresh count
            for (int i =0; i<4; i++){
                int nr = r + delrow[i];
                int nc = c + delcol[i];
                if (nr >= 0 && nc >= 0 && nr <n && nc<m && vis[nr][nc]== 0 && mat[nr][nc] == 1){
                    vis[nr][nc] = 2;
                    freshCount--;
                    q.push({{nr,nc},t+1});
                }
            }
        }
        
        // if there are no fresh oranges left then return the time taken to rot all oranges else return -1
        return freshCount == 0 ? tm : -1;
    }
};


int main(){
    Solution s;
    vector<vector<int>> mat = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    
    int result = s.orangesRotting(mat);
    
    cout << "Time taken to rot all oranges: " << result << endl;
    
    return 0;
}