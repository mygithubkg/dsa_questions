#include<iostream>

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
    
    void inserting(Node* node, int key){
        
    }
    Node* insert(Node* node, int key) {
        
        if (node == NULL) 
        return new Node(key);    
    
        // If the key is already present in the tree,
        // return the node
        if (node->data == key) 
            return node;
        
        // Otherwise, recur down the tree/ If the key
        // to be inserted is greater than the node's key,
        // insert it in the right subtree
        if (node->data < key) 
            node->right = insert(node->right, key);
        
        // If the key to be inserted is smaller than 
        // the node's key,insert it in the left subtree
        else 
            node->left = insert(node->left, key);
        
        // Return the (unchanged) node pointer
        return node;
    }
};

int main(){
    Solution s;
    Node* root = NULL;
    
    root = s.insert(root, 50);
    s.insert(root, 30);
    s.insert(root, 20);
    s.insert(root, 40);
    s.insert(root, 70);
    s.insert(root, 60);
    s.insert(root, 80);

    // The tree is now:
    //         50
    //        /  \
    //      30   70
    //     / \   / \
    //   20  40 60 80

    return 0;
}