#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

// Tree Node
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
    void addleft(Node* root, vector<int> &res){
        Node* curr = root->left;
        while (curr){
            if (!isLeaf(curr)) res.push_back(curr->data);
            if (curr->left){
                curr = curr->left;
            }else{
                curr = curr->right;
            }
        }
    }
    
    void addleaf(Node* root, vector<int> &res){
        if (isLeaf(root))
        {
            res.push_back(root->data);
            return;
        }
        
        if (root->left) addleaf(root->left, res);
        if (root->right) addleaf(root->right, res);
    }
    
    void addright(Node* root, vector<int> &res){
        Node* curr = root->right;
        stack<int> temp;
        
        while (curr){
            if (!isLeaf(curr)) temp.push(curr->data);
            if (curr->right){
                curr = curr->right;
            }else{
                curr = curr->left;
            }
        }
        while (!temp.empty()){
            res.push_back(temp.top());
            temp.pop();
        }
    }
    bool isLeaf(Node* root){
        return (!root->left && !root->right);
    }




    vector<int> boundaryTraversal(Node *root) {
        vector<int> res; 
        if(!root) return res;
        if (!isLeaf(root)) res.push_back(root->data);
        
        addleft(root,res);
        addleaf(root,res);
        addright(root,res);
        return res;
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution obj;
    vector<int> ans = obj.boundaryTraversal(root);
    for (auto i: ans){
        cout << i << " ";
    }
    return 0;
}