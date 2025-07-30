#include <iostream>
#include <vector>
#include <algorithm>

// Q1 question is ---
// You are given an array of non-negative integers height representing an elevation map where the width of each bar is 1. Compute how much water it can trap after raining. 💧

// Test case 1 ---
// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]

// Output: 6

// Test case 2 ---
// Input: height = [4,2,0,3,2,5]

// Output: 9

// We will find left max and right max for each index and then calculate the water that can be trapped at that index.

using namespace std;

class Solution {
    public:
    int waterTrap(vector<int> &height){
        int n = height.size();
        int totalwater = 0;
        for (int i = 0; i <n; i++){
            int leftmax = 0;
            for (int j=0; j<=i; j++){
                leftmax = max(leftmax,height[j]);
            }
            int rightmax = 0;
            for (int j=i; j<n; j++){
                rightmax = max(rightmax,height[j]);
            }
            totalwater += min(leftmax, rightmax) - height[i];
        }
        return totalwater;
    }
};

int main(){
    Solution sol;
    vector<int> height1 = {0,1,0,2,1,0,1,3,2,1,2,1}; // Example 1
    vector<int> height2 = {4,2,0,3,2,5}; // Example 2

    int result1 = sol.waterTrap(height1);
    cout << "Water trapped in first case: " << result1 << " units" << endl;

    int result2 = sol.waterTrap(height2);
    cout << "Water trapped in second case: " << result2 << " units" << endl;


    return 0;
}

