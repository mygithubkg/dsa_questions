#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

class Solution {
    public:
      // Function to find the maximum number of meetings that can
      // be performed in a meeting room.
      int maxMeetings(vector<int>& start, vector<int>& end) {
          vector<pair<int,int>> ans;
          
          int n = start.size();
          for (int i = 0; i <n; i++){
              ans.push_back({end[i],start[i]});
          }
          
          sort(ans.begin(),ans.end());
          
          int last_updated = ans[0].first;
          int count = 1;
          
          for (int i=1; i<n; i++){
              if (ans[i].second > last_updated){
                  count++;
                  last_updated = ans[i].first;
              }
          }
          return count;
      }
      
  };

  int main(){
      Solution obj;
      vector<int> start = {1, 3, 0, 5, 8, 5};
      vector<int> end = {2, 4, 6, 7, 9, 9};
      cout << obj.maxMeetings(start,end) << endl; // Output: 4
      return 0;
  }