#include<iostream>

using namespace std;

struct Node
{
    int data;
    Node* left, * right;
}; 

class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int toSum(Node* node){
        if (!node) return 0;
        
        int old_value = node->data;
    
        // Recursively convert left and right subtrees
        int left_sum = toSum(node->left);
        int right_sum = toSum(node->right);
        
        // Update the current node's value to the sum of its left and right subtrees
        node->data = left_sum + right_sum;
        
        // Return the total sum including the original value of the node
        return node->data + old_value;
    }
    
    
    
    void toSumTree(Node *node)
    {
        toSum(node);
    }
};

int main(){
    // Example usage of the toSumTree function
    Node* root = new Node{10, new Node{20}, new Node{30}};
    Solution sol;
    sol.toSumTree(root);
    
    cout << "Root value after conversion: " << root->data << endl; // Output: 50 (20 + 30)
    
    return 0;
}

