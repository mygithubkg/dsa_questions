#include<iostream>


using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}


// O(N) approach to implement diameter of tree

class Solution {
    public:
    int findmax(Node*root,int &maxi){
        
        if (root == NULL) return 0;
        
        int lh = findmax(root -> left, maxi);
        int rh = findmax(root -> right, maxi);
        
        maxi = max(maxi, lh+rh);
        
        return 1 + max(lh,rh);
    }
    
    int diameter(Node* root) {
        int maxi = 0;
        findmax(root,maxi);
        
        return maxi;
        
    }
};

int main(){
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    
    Solution obj;
    cout << "Diameter of the tree: " << obj.diameter(root) << endl; // Output: 4
    
    return 0;  
}
