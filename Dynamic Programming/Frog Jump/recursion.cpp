#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

// Frog Jump problem using recursion
// Time Complexity - O(2^n) and Space Complexity - O(n) for recursion stack

class Solution {
  public:
  
    int f(int n, vector<int> &height){
        if (n==0) return 0;
        
        int left = f(n-1, height) + abs(height[n] - height[n-1]);
        int right = INT_MAX;
        
        if (n > 1) right  = f(n-2, height) + abs(height[n] - height[n-2]);
        
        return min(left,right);
    }
  
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size() - 1;
        int ans = f(n, height);
        
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> height = {10, 30, 40, 20, 50}; // Example heights
    int result = sol.minCost(height);
    
    cout << "Minimum cost to reach the top: " << result << endl;
    
    return 0;
}
