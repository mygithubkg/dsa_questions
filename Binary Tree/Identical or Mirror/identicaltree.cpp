#include<iostream>

using namespace std;


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};


class Solution {
  public:
    // Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2) {
        if (r1==NULL && r2==NULL) return true;
        
        return (r1->data == r2->data) && (isIdentical(r1->left,r2->left)) && (isIdentical(r1->right,r2->right));
    }
};

int main(){
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    
    Solution s;
    cout << s.isIdentical(root1, root2) << endl; // Output: 1 (true)
    
    return 0;
}