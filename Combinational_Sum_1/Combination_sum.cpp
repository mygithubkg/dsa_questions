#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;    


set<vector<int>> s;
void c_s(vector<int> &A, int B, int i , vector<int> &combination, vector<vector<int>> &ans){
    if (i==A.size() || B <0){
        return;
    }
    if (B ==0){
        if (s.find(combination) == s.end()){
            ans.push_back(combination);
            s.insert(combination);
        }
        
        return;
    }
    
    
    combination.push_back(A[i]);
    // Taking value one time 
    c_s(A,B-A[i],i+1,combination,ans);
    
    // Taking values multiple times
    c_s(A,B-A[i],i,combination,ans);
    
    // Backtrack for exclusion case
    combination.pop_back();
    
    // Exclude it
    c_s(A,B,i+1,combination,ans);
}
int main() {
    vector<int> A = {2,3,6,7};
    int B = 7;
    vector<vector<int>> ans;
    vector<int> combination;
    s.clear();
    sort(A.begin(),A.end());
    c_s(A,B, 0, combination,ans);
    sort(ans.begin(),ans.end());
    for (auto x : ans){
        for (auto y : x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}

