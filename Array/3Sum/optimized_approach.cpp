#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        sort(arr.begin(),arr.end());
        for (int i = 0; i < arr.size() - 2; i++){
            int left = i +1;
            int right = arr.size() -1;
            while (left < right){
                int ans = arr[i] + arr[left] +arr[right];
                if (ans == target){
                    return true;
                }
                else if (ans > target){
                    right--;
                }
                else{
                    left++;
                }
            }
        }
        return false;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int target = 9;
    Solution sol;
    if (sol.hasTripletSum(arr, target)) {
        cout << "Triplet with the given sum exists." << endl;
    } else {
        cout << "No triplet with the given sum exists." << endl;
    }
    return 0;
}