#include<iostream>
#include<climits>

using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
    public:
      // Function to find largest subtree sum.
      int largest(Node* node, int &ans){
        //   base case for recursion if reaches last cell
          if (!node) return 0;
          
        //   if leaf node return its value
          int left = largest(node->left,ans);
          int right = largest(node->right,ans);
          
          ans = max(ans,left + right + node->data);
          
          return left + right + node->data;
      }
      int findLargestSubtreeSum(Node* root)
      {
          int ans = INT_MIN;
          largest(root,ans);
          
          return ans;
      }
  };

  int main(){
        // let's assume a binary tree is created here
        Node* root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->left = new Node(4);
        root->left->right = new Node(5);
        root->right->left = new Node(6);
        root->right->right = new Node(7);
        // create an instance of the Solution class
        Solution sol;
        // call the findLargestSubtreeSum function and print the result
        int result = sol.findLargestSubtreeSum(root);
        cout << "Largest subtree sum: " << result << endl;
  }