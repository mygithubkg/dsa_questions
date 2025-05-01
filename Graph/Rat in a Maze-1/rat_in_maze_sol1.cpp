#include<iostream>
#include<vector>

using namespace std;


class Solution {
    public:

    void detect(vector<vector<int>> &mat, int x,int y, int n , int m , string path,vector<string> &ans){

        // base case for recursion if reaches last cell
        if (x == n-1 && y == m-1){
            ans.push_back(path);
            return;
        }

        // marking the visited cell

        mat[x][y] =0;

        vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<char> moves = {'D', 'R', 'U', 'L'};

        for (int i =0; i<4; i++){
            int nx = x + directions[i].first;
            int ny = y + directions[i].second;

            if (nx >=0 && nx <n && ny>=0 && ny<m && mat[nx][ny]==1){
                detect(mat,nx,ny,n,m,path + moves[i], ans);
            }
        }
        mat[x][y] = 1;

    }

    vector<string> findpath(vector<vector<int>> &mat){
        int n = mat.size();
        int m = mat[0].size();
        vector<string> ans;

        if (mat[0][0] == 0 || mat[n-1][m-1]==0){
            return {};
        }

        detect(mat,0,0,n,m,"",ans);
        return ans;
    }

};

int main(){
    int t = 1;
    while (t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<string> ans = obj.findpath(mat);
        if (ans.size() == 0){
            cout << -1 << endl;
        } else {
            for (auto path : ans){
                cout << path << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

// To run in terminal use the following command:
// g++ -o rat_in_maze rat_in_maze_sol1.cpp && ./rat_in_maze
// Input:
// 4 4
// 1 0 0 0
// 1 1 0 1
// 0 1 0 0

// 1 1 1 1

// or use 
