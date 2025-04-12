#include<iostream>
#include<vector>

using namespace std;


struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


// return the Kth Smallest element in the given BST rooted at 'root'

class Solution {
    public:
      // Return the Kth smallest element in the given BST
      int kthSmallest(Node *root, int k) {
          vector<int> ans;
          inorder(root,ans);
          if (k <= ans.size()){
              return ans[k-1];
          }
          return -1;
      }
      void inorder(Node*root, vector<int> &ans){
          if (!root) return;
          
          inorder(root->left, ans);
          ans.push_back(root->data);
          inorder(root->right,ans);
      }
  };
  

int main(){
    Solution s;
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(35);

    int k = 3; // Find the 3rd largest element
    cout << s.kthSmallest(root, k) << endl; // Output: 25

    return 0;
}