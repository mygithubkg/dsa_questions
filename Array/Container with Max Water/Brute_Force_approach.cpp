/* You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the i-th line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water. Return the maximum amount of water a container can store. 💧

Test case 1 ---
Input: height = [1,8,6,2,5,4,8,3,7]

Output: 49

Explanation: The vertical lines at index 1 (height 8) and index 8 (height 7) form the container with the maximum area. The width is 8 - 1 = 7, and the height is limited by the shorter line, which is 7. Area = 7 * 7 = 49.

Test case 2 ---
Input: height = [1,1]

Output: 1 */


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {

  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        int area = 1;
        for (int i =0; i < n ; i++){
            int ele1 = arr[i];
            for (int j = i+1; j <n ; j++){
                int ele2 = arr[j];
                int length = min(ele1,ele2);
                int width = abs(j-i);
                area = max(area, length * width);
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