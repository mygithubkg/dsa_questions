#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;


class Solution {
  public:
  
    int f(int ind1, int ind2, string &s1, string &s2, vector<vector<int>> &dp){
        if (ind1 < 0 || ind2 < 0) return 0;
        
        if (dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
        if (s1[ind1] == s2[ind2]) return 1 + f(ind1 -1, ind2 -1, s1,s2,dp);
        
        return dp[ind1][ind2] = max(f(ind1-1,ind2,s1,s2,dp),f(ind1,ind2-1,s1,s2,dp));
    }
    
    int lcs(string &s1, string &s2) {
        // code here
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        return f(n-1,m-1,s1,s2,dp);
    }
};



int main(){
    Solution sol;
    string s1 = "abcde"; // Example string 1
    string s2 = "ace";   // Example string 2

    int result = sol.lcs(s1, s2);
    cout << "Length of Longest Common Subsequence = " << result << endl;

    return 0;
}