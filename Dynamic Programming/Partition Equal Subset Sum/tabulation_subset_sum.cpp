#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric> // For accumulate function

using namespace std;

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
            
        int sum = accumulate(arr.begin(),arr.end(),0);
        // all dp elements are initialized to false by default
        vector<vector<bool>> dp(arr.size()+1,vector<bool>(sum+1,false));
        // if the sum is odd, we cannot partition the array into two equal subsets
        // because the sum of two equal subsets must be even
        if (sum % 2 != 0) return false;

        // if the sum is 0, we can always form a subset with sum 0 (empty subset)
        // so we set the first column of the dp array to true
        for (int i= 0; i <= arr.size(); i++){
            dp[i][0] = true;
        }
        
        // fill the dp array using the tabulation approach
        // we iterate over the elements of the array and the possible sums
        for (int i =1; i <= arr.size(); i++){
            for (int j=1 ; j <= sum/2; j++){
                // if the current element is greater than the current sum,
                // we cannot include it in the subset
                if (arr[i-1] > j) {
                    dp[i][j] = dp[i-1][j];
                }
                // if the current element is less than or equal to the current sum,
                // we have two choices: include it or exclude it
                else{
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
                }
            }
        }
        
        return dp[arr.size()][sum/2];
    }
};



// space optimization is possible

#include <bits/stdc++.h>
using namespace std;

// Returns true if arr[] can be partitioned in two
// subsets of equal sum, otherwise false
bool equalPartition(vector<int>& arr) {
  
    // Calculate sum of the elements in array
    int sum = accumulate(arr.begin(), arr.end(), 0);
    
    // If sum is odd, there cannot be two 
    // subsets with equal sum
    if (sum % 2 != 0) 
        return false;

    sum = sum / 2;
    
    int n = arr.size();
    vector<bool> prev(sum + 1, false), curr(sum + 1);

    // Mark prev[0] = true as it is true
    // to make sum = 0 using 0 elements
    prev[0] = true;

    // Fill the subset table in
    // bottom up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j < arr[i - 1])
                curr[j] = prev[j];
            else
                curr[j] = (prev[j] || prev[j - arr[i - 1]]);
        }
        prev = curr;
    }
    return prev[sum];
}