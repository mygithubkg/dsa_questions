#include<iostream>
#include<stack>

using namespace std;


class Solution {
    public:
      bool isBalanced(string& s) {
          stack<char> st;
        //   Checking opening brackets
          for (int i =0; i < s.size(); i++){
              if (s[i] == '{' || s[i] == '[' || s[i] == '('){
                  st.push(s[i]);
              }
            //   checking closing brackets
              else{
                  if ((s[i] == '}' && st.top() == '{') || (s[i] == ']' && st.top() == '[') || (s[i] == ')' && st.top() == '(')
                  ){
                      st.pop();
                  }
                  else{
                      return false;
                  }
              }
          }
          
          return st.size() == 0;
          
      }
  };



// without using stack O(n) time and O(1) space

// C++ program to check if parentheses are balanced
// Check if characters match
bool checkMatch(char c1, char c2){
    if (c1 == '(' && c2 == ')') return true;
    if (c1 == '[' && c2 == ']') return true;
    if (c1 == '{' && c2 == '}') return true;
    return false;
}

// Check if parentheses are balanced
bool isBalanced(string& s){
  
    // Initialize top to -1
    int top = -1;
    for (int i = 0; i < s.length(); ++i){
      
        // Push char if stack is empty or no match
        if (top < 0 || !checkMatch(s[top], s[i])){
            ++top;
            s[top] = s[i];
        }
        else{
          
            // Pop from stack if match found
            --top;
        }
    }
  
    // Return true if stack is empty (balanced)
    return top == -1;
}

int main(){
    string s = "{([])}";
    cout << (isBalanced(s) ? "true" : "false") << endl;
    return 0;
}
