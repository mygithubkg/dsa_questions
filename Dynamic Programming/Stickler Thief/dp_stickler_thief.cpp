#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

class Solution{
    public:
    // Function to find the maximum sum of non-adjacent elements.
    int f(int i, vector<int> &arr, vector<int> &dp){
        if (i==0) return arr[0];
        if (dp[i] != -1) return dp[i];

        int take = arr[i] + f(i-2, arr,dp); 
        int skip = f(i-1, arr,dp);

        return dp[i] = max(take,skip);
    }

    int findMaxSum(vector<int>& arr) {
        // Code here
        int n = arr.size();
        if (n == 0) return 0;
        if (n == 1) return arr[0];
        
        // case 1 - from 0 to n-2
        vector<int> dp1(n,-1);
        vector<int> temp1(arr.begin(), arr.end() - 1);
        int case1 = f(n-2,temp1,dp1);

        // case 2 - from 1 to n-1
        vector<int> dp2(n,-1);
        vector<int> temp2(arr.begin() + 1, arr.end());
        int case2 = f(n - 2, temp2, dp2);

        return max(case1,case2);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {3, 2, 5, 10, 7}; // Example array
    int result = sol.findMaxSum(arr);
    
    cout << "Maximum sum of non-adjacent elements: " << result << endl;
    
    return 0;
}