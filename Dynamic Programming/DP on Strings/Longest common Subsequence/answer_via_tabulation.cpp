#include<iostream>
#include<vector>
#include<algorithm>
#include<string>


using namespace std;

class Solution {
    public:
    int lcs(string &s1, string &s2){
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        // Base case: if either string is empty, LCS is 0
        for(int i = 0; i < n; i++) { 
            dp[i][0] = 0; // First column (s2 is empty)
        }
        for(int j = 0; j < m; j++) { 
            dp[0][j] = 0; // First row (s1 is empty)
        }
        // Fill the dp table
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(s1[i] == s2[j]) {
                    dp[i][j] = 1 + dp[i-1][j-1]; // Characters match
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // Characters do not match
                }
            }
        }
        return dp[n-1][m-1]; // Return the length of LCS
    }
};

int main() {
    Solution sol;
    string s1 = "abcde"; // Example string 1
    string s2 = "ace";   // Example string 2

    int result = sol.lcs(s1, s2);
    cout << "Length of Longest Common Subsequence = " << result << endl;

    return 0;
}