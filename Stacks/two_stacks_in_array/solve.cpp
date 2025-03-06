#include<iostream>
#include<stack>
using namespace std;    
class twoStacks {
    public:
      stack<int> s1, s2;
      twoStacks() {}
  
      // Function to push an integer into the stack1.
      void push1(int x) {
          s1.push(x);
      }
  
      // Function to push an integer into the stack2.
      void push2(int x) {
          s2.push(x);
      }
  
      // Function to remove an element from top of the stack1.
      int pop1() {
          if (s1.size()==0){
              return -1;
          }
          int x = s1.top();
          s1.pop();
          return x;
      }
  
      // Function to remove an element from top of the stack2.
      int pop2() {
          // code here
          if (s2.size()==0){
              return -1;
          }
          int x = s2.top();
          s2.pop();
          return x;
      }
  };
  