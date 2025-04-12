#include<iostream>

using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};


int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    
    int ceil = -1;
    
    while (root){
        if (input == root->data){
            ceil = root->data;
            return ceil;
        }
        else if (input > root->data){
            root = root->right;
        }
        else{
            ceil = root->data;
            root= root->left;
        }
    }
    return ceil;
}

int main(){
    // Example usage of the findCeil function
    Node* root = new Node{10, new Node{5}, new Node{15}};
    
    cout << "Ceil of 7: " << findCeil(root, 7) << endl; // Output: 10
    cout << "Ceil of 12: " << findCeil(root, 12) << endl; // Output: 15
    
    return 0;
}