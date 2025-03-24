#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
    public:
      // Function to find the next greater element for each element of the array.
      vector<int> nextLargerElement(vector<int>& arr) {
          int n = arr.size();
          
          vector<int> res(n,-1);
          stack<int> st;
          
          
          for (int i = n-1; i>=0; i--){
              
              while (!st.empty() && st.top() <= arr[i]){
                  st.pop();
              }
              
              if (!st.empty()){
                  res[i] = st.top();
              }
              
              st.push(arr[i]);
          }
          
          return res;
          
      }
  };

int main(){
    Solution sol;
    vector<int> arr = {1,3,2,4};
    vector<int> res = sol.nextLargerElement(arr);
    for (int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}