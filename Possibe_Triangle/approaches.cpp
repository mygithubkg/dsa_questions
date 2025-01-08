#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


// O(n^2) Expected Approach using Two Pointers
    
int countTriangles(vector<int>& arr) {
    //  O(n^3) approach
    sort(arr.begin(),arr.end());
    int n = arr.size();
    int ans = 0;
    for (int i = 2; i <n ; i++){
        // taking other two values before i
        int left = 0, right = i-1;
        while (left < right){
            // if left + right combination is greater than no need 
            // to go left as already sorted means all combinations will be greatwr after this
            if (arr[left] + arr[right] > arr[i]){
                ans += right - left;
                right--;
            }
            else{
                // else find larger side
                left++;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {3,4,6,7};
    int ans = countTriangles(arr);
    cout<<ans;
    return 0;
}

//   O(n^3) approach

// int istriangle(int i , int j , int k){
//     if (i+j > k && i+k > j && j+k > i){
//         return true;
//     }
//     return false;
// }
// // Function to count the number of possible triangles.
// int countTriangles(vector<int>& arr) {
//     
//     int n = arr.size();
//     int ans = 0;
//     for (int i =0; i <n; i++){
//         for (int j = i+1; j < n; j++){
//             for (int k = j+1; k< n;k++){
//                 if (istriangle(arr[i],arr[j],arr[k])){
//                     ans +=1;
//                 }
//             }
//         }
//     }
//     return ans;
// }