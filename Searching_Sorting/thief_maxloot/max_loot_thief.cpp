#include<iostream>
#include<vector>

using namespace std;

class Solution {
  public:
    // Function to find the maximum money the thief can get.(consecutive houses not allowed)
    int findMaxSum(vector<int>& arr) {
        int ans = 0;
        if (arr.size()==0 ) return 0;
        if (arr.size()== 1) return arr[0];
        
        int secondlast = 0;
        int last = arr[0];
        for (int i =1; i< arr.size(); i++){
            ans = max(arr[i]+secondlast,last);
            secondlast = last;
            last = ans;
        }
        
        
        return ans;
    }
};