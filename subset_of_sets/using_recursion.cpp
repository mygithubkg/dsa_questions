#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

void allsubsets(string &s, string ans, int i, vector<string> &store){
    if (i == s.size()){
        store.push_back(ans) ;
        return;
    }
    
    // include
    allsubsets(s,ans + s[i],i+1,store);
    
    //exclude
    allsubsets(s,ans,i+1,store);
}

int main(){
    string s = "abc";
    vector<string> store;
    allsubsets(s,"",0,store);
    sort(store.begin(), store.end());
    for (auto it: store){
        cout<<it<<" ";
    }
    return 0;
}