#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution{
    public:
    bool isSubsetSum(vector<int>&arr, int sum){
        vector<vector<int>> dp(arr.size(),vector<int>(sum+1,0));

        int n = arr.size();
        // Base case when already true condition is met
        dp[0][arr[0]] = true;
        for (int i = 0; i<n ; i++) dp[i][0] = true;

        for (int i = 1; i < n; i++){
            for (int target = 1; target <=sum; target++){
                bool taken = false;
                if (target > arr[i]){
                    taken = dp[i-1][target - arr[i]];
                }
                bool nottaken = dp[i-1][target];
                dp[i][target] = taken || nottaken;
            }
        }

        return dp[n-1][sum];  
    }
};


int main (){
    Solution sol;
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    if (sol.isSubsetSum(arr, sum)) {
        cout << "Subset with given sum exists." << endl;
    } else {
        cout << "No subset with given sum exists." << endl;
    }

    return 0;
}