#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution {
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    void inorder (Node* root, vector<int> &nodes){
        if (!root) return;
        inorder(root->left, nodes);
        nodes.push_back(root->data);
        inorder(root->right, nodes);
    }
    void ConstructNodes(Node *root,vector<int> &nodes, int &index){
        if (!root) return;
        ConstructNodes(root->left,nodes,  index);
        root->data = nodes[index++];
        ConstructNodes(root->right, nodes, index);
    }
    
    Node *binaryTreeToBST(Node *root) {
        vector<int> nodes;
        inorder(root, nodes);
        sort(nodes.begin(),nodes.end());
        int index = 0;
        ConstructNodes(root,nodes,index);
        return root;
        
    }
};

int main() {
    // Example usage
    Node* root = new Node(10);
    root->left = new Node(30);
    root->right = new Node(15);
    root->left->left = new Node(20);
    
    Solution sol;
    Node* bstRoot = sol.binaryTreeToBST(root);
    
    // Output the BST in-order (for testing)
    vector<int> bstNodes;
    sol.inorder(bstRoot, bstNodes);
    
    cout << "In-order traversal of the BST: ";
    for (int val : bstNodes) {
        cout << val << " ";
    }
    
    return 0;
}   