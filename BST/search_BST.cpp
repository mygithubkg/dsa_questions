#include<iostream>

using namespace std;    

struct Node
{
    int data;
    Node* left, * right;
};

bool search(Node* root, int x) {
    if (!root) return false;
    
    if (root->data == x) return true;
    
    if (x < root->data) {
        return search(root->left, x); // Search in the left subtree
    } else {
        return search(root->right, x); // Search in the right subtree
    }
}

int main() {
    // Example usage of the search function
    Node* root = new Node{10, new Node{5}, new Node{15}};
    
    cout << (search(root, 5) ? "Found" : "Not Found") << endl; // Output: Found
    cout << (search(root, 20) ? "Found" : "Not Found") << endl; // Output: Not Found
    
    return 0;
}