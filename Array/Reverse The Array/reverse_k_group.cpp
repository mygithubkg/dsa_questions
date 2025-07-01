#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
  public:
    void reverseInGroups(vector<int> &arr, int k) {
        int n = arr.size();
        for (int i =0; i<n; i+=k){
            int left =i;
            int right = min(i+k-1,n-1);
            while(left<right){
                swap(arr[left],arr[right]);
                left++;
                right--;
            }
        }
        
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int k = 3;

    Solution sol;
    sol.reverseInGroups(arr, k);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}   