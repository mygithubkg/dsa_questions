#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
    public:
      void detect(vector<int>&KnightPos, vector<int>&targetPos, int N){
          
      }
      int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int N) {
          // Code here
          int n = N;
          queue<pair<pair<int,int>,int>> q;
          vector<vector<int>> vis(n+1,vector<int>(n+1,0));
          
          // Marking knight Position as visited 
          vis[knightPos[0]][knightPos[1]] = 1;
          
          // Creating 8 possible movements of a knight
          
          vector<int> movX = { -2, -1, 1, 2, -2, -1, 1, 2 };
          vector<int> movY = { -1, -2, -2, -1, 1, 2, 2, 1 };
          
          q.push({{knightPos[0],knightPos[1]},0});
          
          // Now using BFS checking all 8 positions
          
          while (!q.empty()){
              int x = q.front().first.first;
              int y = q.front().first.second;
              
              int dis = q.front().second;
              q.pop();
              
              for (int i =0;i<8; i++){
                  int nx = x + movX[i];
                  int ny = y + movY[i];
                  
                  if (nx == targetPos[0] && ny == targetPos[1]){
                      return dis +1;
                  }
                  if (nx >0 && ny>0 && nx<=n && ny<=n && !vis[nx][ny]){
                      vis[nx][ny] = 1;
                      q.push({{nx,ny},dis+1});
                  }
              }
          }
          
          return 0;
      }
  };
int main(){
    int n;
    cin >> n; // Size of the chessboard
    vector<int> knightPos(2), targetPos(2); // Knight and target positions
    cin >> knightPos[0] >> knightPos[1]; // Input knight position
    cin >> targetPos[0] >> targetPos[1]; // Input target position
    
    Solution obj;
    cout << obj.minStepToReachTarget(knightPos, targetPos, n) << endl; // Output minimum steps
    return 0;
}  