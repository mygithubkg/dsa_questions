#include<iostream>

using namespace std;


struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }   
};

class Solution{
    public:

    Node* deleteNode(Node* root, int x){
        if (!root) return root; 

        if (x < root->data){
            root->left = deleteNode(root->left,x);
        }
        else if (x > root-> data){
            root->right = deleteNode(root->right,x);
        }else{
            // No child case
            if (!root->left && !root->right){
                delete root;
                return NULL;
            }
            // One child case
            else if (!root->left || !root->right){
                Node* temp = root->left ? root->left : root->right;
                delete root;
                return temp;
            }
            // Two child case
            else{
                Node* temp = root->right;
                while (temp && temp->left){
                    temp = temp->left;
                }
                root->data = temp->data;
                root->right = deleteNode(root->right,temp->data);
            }
        }
        return root;
    }
};

int main(){
    Solution s;
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);

    int x = 50;
    root = s.deleteNode(root, x);

    // Add code to print the tree if needed

    return 0;
}