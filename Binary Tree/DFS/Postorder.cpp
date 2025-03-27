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


void Postorder(Node* node){
    if (node == NULL){
        return;
    }
    Postorder(node->left);
    Postorder(node->right);
    cout<<node->data<<" ";
    
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Postorder(root);
    return 0;
}