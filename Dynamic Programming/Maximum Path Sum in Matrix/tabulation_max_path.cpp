#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// User function Template for C++

class Solution {
  public:
    bool check(int i, int j, int r, int c){
        if (i >= 0 && j >= 0 && i <r && j <c){
            return true;
        }
        return false;
    }
    
    int maximumPath(vector<vector<int>>& mat) {
        // code here
        int r = mat.size();
        int c = mat[0].size();
        
        for (int i = r-2; i>=0; i--){
            for (int j = 0; j< mat[i].size(); j++){
                int down = check(i+1,j,r,c) ?  mat[i+1][j] : 0;
                int dialeft = check(i+1,j-1,r,c) ? mat[i+1][j-1] : 0;
                int diaright = check(i+1,j+1,r,c) ? mat[i+1][j+1] : 0;
                
                mat[i][j] += max({down,dialeft,diaright});
            }
        }
        sort(mat[0].begin(),mat[0].end());
        return mat[0][c-1];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {5, 10, 20},
        {4, 1, 2},
        {3, 6, 7}
    };
    
    int result = sol.maximumPath(mat);
    cout << "Maximum Path Sum: " << result << endl; // Output: 37
    return 0;
}