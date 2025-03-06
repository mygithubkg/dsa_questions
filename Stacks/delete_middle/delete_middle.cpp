#include<iostream>
#include<stack>
#include<vector>

using namespace std;


class Solution {
    public:
      // Function to delete middle element of a stack.
      void deleteMid(stack<int>& s) {
          int mid = (s.size() + 1) / 2; // Calculate the middle index
          vector<int> v;
          int count = s.size();
          
          // Transfer elements to the vector and skip the middle one
          for (int i = 0; i < count; i++) {
              if (i != (count-mid)) {
                  v.push_back(s.top());
              } else {
                  s.pop(); // Remove the middle element
                  continue;
              }
              s.pop();
          }
          
          // Push the elements back into the stack
          for (int i = v.size() - 1; i >= 0; i--) {
              s.push(v[i]);
          }
      }
  };