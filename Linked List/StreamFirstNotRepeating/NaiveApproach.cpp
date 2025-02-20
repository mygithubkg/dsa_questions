#include<iostream> 
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
    public:
      string FirstNonRepeating(string &s) {
          string ans;
          vector<char> v;
          unordered_map<char,int> mpp;
          for (char ch: s){
              if (mpp.find(ch) == mpp.end()){
                  v.push_back(ch);
                  mpp[ch] = 1;
              }
              else{
                  int index = find(v.begin(),v.end(),ch) - v.begin();
                  if (index < v.size()){
                      v.erase(v.begin()+ index);
                  }
              }
              ans += v.empty() ? '#' : v.front();
          }
          return ans;
          
      }
  };
  