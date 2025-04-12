#include<iostream>
#include<limits.h>
#include<algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    public:
      // Function to check whether a Binary Tree is BST or not.
      
      
      bool checkBST(Node* root,int minval, int maxval){
          if (!root) return true;
          
          if (root->data <= minval || root->data >=maxval){
              return false;
          }
          
          return checkBST(root->left,minval,root->data) && checkBST(root->right,root->data, maxval);
          
      }
      bool isBST(Node* root) {
          return checkBST(root,INT_MIN, INT_MAX);
      }
  };

  int main(){
        Solution s;
        Node* root = new Node(50);
        root->left = new Node(30);
        root->right = new Node(70);
        root->left->left = new Node(20);
        root->left->right = new Node(40);
        root->right->left = new Node(60);
        root->right->right = new Node(80);
        
        cout << s.isBST(root) << endl; // Output: 1 (true)  
  }