#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;    


class Solution {
  public:
  
    bool f (int index,int  target, vector<int> &arr,vector<vector<int>> &dp){
        // Base case 
        if (target == 0) return true;
        if (index == 0) return (arr[index] == target);
        
        if (dp[index][target] != -1) return dp[index][target];
        
        bool taken = false;
        if (target >= arr[index]) taken = f(index-1,target - arr[index], arr,dp);
        bool nottaken = f(index-1,target, arr,dp);
        
        return dp[index][target] = taken || nottaken;
    } 
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        
        vector<vector<int>> dp(arr.size(),vector<int>(sum+1,-1));
        return f(arr.size()-1,sum,arr,dp);
        
    }
};

int main(){
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