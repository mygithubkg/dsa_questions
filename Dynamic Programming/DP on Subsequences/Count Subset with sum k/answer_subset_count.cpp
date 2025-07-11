#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric> // For accumulate function

using namespace std;

class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int totalsum = 0;
        for (int num: arr) totalsum += num;
        int n = arr.size();
        
        // Intital cases 
        
        vector<vector<int>> dp(n,vector<int>(totalsum+1,0));
        if (arr[0] == 0)
            dp[0][0] = 2; // take or not take the zero
        else {
            dp[0][0] = 1;
            if (arr[0] <= totalsum)
                dp[0][arr[0]] = 1;
        }

        
        for (int i = 1; i < n; i++){
            for (int targetsm = 0; targetsm <= totalsum; targetsm++){
                int nottaken = dp[i-1][targetsm];
                int taken = 0;
                if (arr[i] <= targetsm) taken = dp[i-1][targetsm - arr[i]];
                dp[i][targetsm] = taken + nottaken;
            }
        }
        
        return dp[n-1][target];
        
    }
};


// Now we make a dp in tabulation in which we have index and target value and stored if true of false
// Now We can check in how many ways rows are true with that target column to know the possible subset so stroing the ways instread of true or false


int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3}; // Example input array
    int target = 4; // Example target sum

    int result = sol.perfectSum(arr, target);
    cout << "The number of subsets with the given sum is: " << result << endl;

    return 0;
}