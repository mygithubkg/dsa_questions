#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
    public:
    int waterTrap(vector<int> &height, int n){
        vector<int> leftmax(n, 0);
        vector<int> rightmax(n, 0);
        int totalwater = 0;

        for (int i=0; i < n; i++) {
            if (i == 0) {
                leftmax[i] = height[i];
            } else {
                leftmax[i] = max(leftmax[i - 1], height[i]);
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i == n - 1) {
                rightmax[i] = height[i];
            } else {
                rightmax[i] = max(rightmax[i + 1], height[i]);
            }
        }
        for (int i = 0; i < n; i++) {
            totalwater += min(leftmax[i], rightmax[i]) - height[i];
        }
        return totalwater;
    }

};

int main() {
    Solution sol;
    vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; // Example 1
    vector<int> height2 = {4, 2, 0, 3, 2, 5}; // Example 2

    int result1 = sol.waterTrap(height1, height1.size());
    cout << "Water trapped in first case: " << result1 << " units" << endl;

    int result2 = sol.waterTrap(height2, height2.size());
    cout << "Water trapped in second case: " << result2 << " units" << endl;

    return 0;
}