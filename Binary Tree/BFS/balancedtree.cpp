#include<iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    int isBalancedRec(Node* root){
        if (root == NULL){
            return 0;
        }
        
        int lh = isBalancedRec(root ->left);
        int rh = isBalancedRec(root ->right);
        
        if (lh == -1 || rh == -1 || abs(lh - rh) > 1 ) return -1;
        
        return max(lh,rh) +1;
    }
    
    
    bool isBalanced(Node* root) {
        return (isBalancedRec(root) > 0);
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    Solution obj;
    cout << (obj.isBalanced(root) ? "Balanced" : "Not Balanced") << endl; // Output: Balanced
    
    return 0;
}