// We have a wooden plank of length n units. Some ants are walking on the plank, each ant moves with a speed of 1 unit per second, with some moving left and others right.
// When two ants moving in two different directions meet at some point, they change their directions and continue moving again. Assume changing directions does not take any additional time. When an ant reaches one end of the plank at a time t, it falls out of the plank immediately.

// Given an integer n and two integer arrays left[] and right[], the positions of the ants moving to the left and the right, return the time when the last ant(s) fall out of the plank.

// Examples :

// Input: n = 4, left[] = [2], right[] = [0, 1, 3]
// Output: 4
        
// Explanation: As seen in the above image, the last ant falls off the plank at t = 4.


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
 
        int maxTime = 0;
        for (int l : left) maxTime = max(maxTime, l);
        for (int r : right) maxTime = max(maxTime, n - r);
        return maxTime;
    }
};

int main(){
    Solution sol;
    int n = 4;
    vector<int> left = {2};
    vector<int> right = {0, 1, 3};
    
    cout << "Last moment before all ants fall out: " << sol.getLastMoment(n, left, right) << endl;
    
    return 0;
}