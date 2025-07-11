#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
  public:
    int minPathSum(vector<vector<int>>& triangle) {
        // Code here
        int ans = 0;
        
        for (int i= 0; i<triangle.size(); i++){
            vector<int> curr = triangle[i];
            sort(curr.begin(),curr.end());
            ans += curr[0];
        }
        
        return ans;
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
    
    int result = sol.minPathSum(triangle);
    cout << "Minimum Path Sum: " << result << endl; // Output: 11
    return 0;
}