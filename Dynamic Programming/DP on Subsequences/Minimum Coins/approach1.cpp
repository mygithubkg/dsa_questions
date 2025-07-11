#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
    public:
    vector<int> minPartition(int N) {
        // code here
        vector<int> supply  = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        vector<int> ans;
        int i = supply.size() - 1;
        
        while (N != 0){
            if (N - supply[i] >= 0){
                N -= supply[i];
                ans.push_back(supply[i]);
            }
            else{
                i--;
            }
            if (i<0){
                break;
            }
        }
        
        return ans;
    }
};


int main() {
    Solution sol;
    int N = 121; // Example input
    vector<int> result = sol.minPartition(N);
    
    cout << "Minimum coins to make " << N << ": ";
    for (int coin : result) {
        cout << coin << " ";
    }
    cout << endl;

    return 0;
}
// Also instead of checking everytime and subtracting the value, we can use a greedy approach
// by starting from the largest coin and going downwards until we reach 0.
// here we divide it by that num eg target/ that num - 100/6 = 16 so instead of running it 16 times we can just push 16 times 6 in the ans vector
// This is a greedy approach and works for this problem because the denominations are such that they are multiples of each other.

// Note - 
// Greedy approach can fail 
// eg - {9,6,5,1}  and N = 11
// ans will be {9,1,1} but the correct answer is {6,5} because it is minimum number of coins
// So, we have to use DP approach to solve this problem