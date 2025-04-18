#include<iostream>
#include<vector>

using namespace std;

class Solution {
    private:
    void dfs(vector<vector<int>> &ans,vector<int> delrow,vector<int> delcol, int iniColor, int newColor,int sr, int sc){
        // changing to new colour 
        ans[sr][sc] = newColor;
        // base row and column to check matrix boundary 
        int row = ans.size();
        int col = ans[0].size();
        
        // checking for the 4 directions
        // up, right, down, left
        for (int i = 0; i <4; i++){
            int nrow = sr + delrow[i];
            int ncol = sc + delcol[i];
            // checking for the boundary and if the new color is not equal to the initial color
            if (nrow >= 0 && nrow<row && ncol >=0 && ncol <col && ans[nrow][ncol] !=newColor && ans[nrow][ncol]==iniColor){
                dfs(ans,delrow,delcol,iniColor,newColor,nrow,ncol);
            }
        }
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                int newColor) {
        // Code here
        vector<vector<int>> ans = image;
        int iniColor = ans[sr][sc];
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,1,0,-1};
        dfs(ans,delrow,delcol,iniColor,newColor, sr, sc);
        return ans;
        
    }
};

int main(){
    Solution s;
    vector<vector<int>> image = {
        {1, 1, 0},
        {1, 0, 1},
        {0, 1, 1}
    };
    int sr = 1, sc = 1, newColor = 2;

    vector<vector<int>> result = s.floodFill(image, sr, sc, newColor);

    cout << "Flood Fill Result:" << endl;
    for (const auto& row : result) {
        for (const auto& pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}