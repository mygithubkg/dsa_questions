#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>


using namespace std;

class Solution {

  public:
    int minDifference(vector<int>& arr) {
       int totalsum = 0;
       for (int num : arr) totalsum += num;
       
        int k = totalsum;
        
        vector<vector<bool>> dp(arr.size(),vector<bool>(totalsum+1,false));
        // It is true when subset sum is 0;
        for (int i = 0; i< arr.size(); i++) dp[i][0] = true;
        if (arr[0] <= k) dp[0][arr[0]] = true;
        
        
        for (int i = 1; i< arr.size(); i++){
            for (int target = 1; target <=k; target++){
                bool nottaken = dp[i-1][target];
                bool taken = false;
                
                
                if (arr[i] <= target) taken = dp[i-1][target - arr[i]];
                dp[i][target] = taken || nottaken;
                
            }
        }
        
        // Considering only last row of dp to know which value of subset are possible 
        // eg - {3,2,7} ---- so max possible is 12 then  0, 2,3,5,7,9,10,12 column are true rest false
        
        int mini = INT_MAX;
        for (int s1 = 0; s1<=totalsum/2; s1++){
            if (dp[arr.size()-1][s1] == true){
                int s2 = totalsum - s1;
                mini = min(mini, abs(s2 - s1));
            }
        }
        
        return mini;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 6, 11, 5}; // Example input array

    int result = sol.minDifference(arr);
    cout << "The minimum difference between two subsets is: " << result << endl;

    return 0;
}   