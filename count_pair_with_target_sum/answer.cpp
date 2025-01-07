#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int countPairs(vector<int> &arr, int target) {
    // O(n) Time Complexity and O(n) space Complexity 
    
    int count = 0;
    unordered_map <int, int> mpp;
    for (int i = 0; i < arr.size(); i++){
        int more = target - arr[i];
        if(mpp.find(more) != mpp.end()){
            count += mpp[more];
        }
        mpp[arr[i]]++;
    }
    
    return count;
    
    // Complexity O(n^2)
    // int count = 0;
    // for (int i = 0; i < arr.size(); i++){
    //     for (int j = i+1 ; j < arr.size(); j++){
    //         if (arr[i] + arr[j] == target){
    //             count ++;
    //         }
    //     }
    // }
    // return count;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    int target = 5;
    int ans = countPairs(arr, target);
    cout<<ans;
    return 0;
}