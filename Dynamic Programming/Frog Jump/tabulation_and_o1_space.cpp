#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

// Frog Jump problem using tabulation and O(1) space
// Time Complexity - O(n) and Space Complexity - O(1)

class Solution {
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        int prev = 0;       // dp[i - 1]
        int prev2 = 0;      // dp[i - 2]

        for (int i = 1; i < n; ++i) {
            int jumpOne = prev + abs(height[i] - height[i - 1]);
            int jumpTwo = INT_MAX;
            if (i > 1)
                jumpTwo = prev2 + abs(height[i] - height[i - 2]);

            int curr = min(jumpOne, jumpTwo);

            // Update for next iteration
            prev2 = prev;
            prev = curr;
        }

        return prev;  // prev holds the cost to reach the last stone
    }
};
int main() {
    Solution sol;
    vector<int> height = {10, 30, 40, 20, 50}; // Example heights
    int result = sol.minCost(height);
    
    cout << "Minimum cost to reach the top: " << result << endl;
    
    return 0;
}
