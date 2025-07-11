#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric> // For accumulate function

using namespace std;

// Decoding the problem 
// it says = s1 + s2 = total sum
//  s1 - s2 = difference 
// which tell s1 = (total sum + difference )/2
// basically the problem is to find the number of ways we can get the target sum s1 and nothing else 

class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
        int totalsum = 0;
        for (int num : arr) totalsum += num;
        
        int n = arr.size();
        
        int target = (totalsum + d)/2;
        if (totalsum < d  || (totalsum + d) %2 != 0) return 0;
        
        
        vector<vector<int>> dp(n,vector<int>(target+1,0));
        
        if (arr[0] == 0){
            dp[0][0] = 2; // May be taken or not taken 
        }else{
            dp[0][0] = 1;
            if (arr[0] <= target) dp[0][arr[0]] = 1;
        }
        
        
        
        for (int i = 1; i <n; i++){
            for (int j = 0; j<= target; j++){
                int nottaken = dp[i-1][j];
                int taken = 0;
                if (arr[i] <= j) taken = dp[i-1][j-arr[i]];
                dp[i][j] = taken + nottaken;
            }
        }
        
        return dp[n-1][target];
        
        
    }
};


int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4}; // Example input array
    int d = 1; // Example difference

    int result = sol.countPartitions(arr, d);
    cout << "The number of partitions with the given difference is: " << result << endl;

    return 0;
}