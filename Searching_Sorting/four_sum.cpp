#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<vector<int>> fourSum(vector<int> &arr, int target){
    vector<vector<int>> ans;
    if(arr.empty()) return ans;
    sort(arr.begin(),arr.end());
    int size = arr.size();

    for (int i =0; i<size-3; ++i){
        if (i>0 && arr[i] ==arr[i-1]) continue; //To avoid duplicates
        for (int j = i+ 1; j<size-2; ++j){
            if (j>i+1 && arr[j] == arr[j-1]) continue;
            int left = j+1;
            int right = size-1;
            while (left <right){
                int total = arr[left] + arr[right] + arr[i] + arr[j];
                if (total == target){
                    ans.push_back({arr[left] , arr[right] , arr[i] , arr[j]});
                    while (left <right && arr[left] == arr[right]) ++left;
                    while (left <right && arr[right] == arr[left]) --right;
                    ++left;
                    --right;
                }
                else if (total<target){
                    ++left;
                }else{
                    --right;
                }
            }
        }
    }
    return ans;
}





int main(){
    vector<int> arr = {0,0,2,1,1};
    int target = 3;
    vector<vector<int>> ans = fourSum(arr, target);
    for (auto &v: ans){
        for (int &u: v){
            cout<< u<<" ";
        }
        cout<<endl;
    }



}