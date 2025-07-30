#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;    
// using Two Pointer Technique for Optimal Approach - O(n) time complexity and O(1) space complexity

class Solution {

  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        int area = 0;
        int left = 0, right = n-1;
        
        while(left<right){
            int h = min(arr[left],arr[right]);
            int w = right - left;
            area = max(area,h*w);
            
            if(arr[left] < arr[right]){
                left++;
            }else{
                right--;
            }
        }
        return area;
    }
};

int main(){
    vector<int> arr = {1,8,6,2,5,4,8,3,7};
    Solution sol;
    cout << "Maximum water that can be contained: " << sol.maxWater(arr) << endl;
    return 0;
}