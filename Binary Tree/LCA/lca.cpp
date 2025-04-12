#include<iostream>
#include<vector>


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


class Solution {
    public:
    bool findpath(Node* root, vector<Node*>&path, int k){
        if (root == NULL) return false;
            
            path.push_back(root);
    
            if (root->data == k){
                return true;
            }
    
            if (findpath(root->left, path, k) || findpath(root->right, path, k)){
                return true;
            }
    
            path.pop_back();
            return false;
    }

    Node* lca(Node* root,int k1, int k2){
        vector<Node*> path1, path2;

        if (!findpath(root, path1,k1) || !findpath(root, path2,k2)){
            return NULL;
        }
        int i = 0;
        // Find the first different node in the paths
        // The last common node is the LCA
        for (; i <path1.size() && i <path2.size();i++){
            if (path1[i] != path2[i]){
                return path1[i-1];
            }
        }
        // If one path is a prefix of the other, return the last node in the shorter path
        // This case can happen if one of the nodes is an ancestor of the other
        return path1[i-1];
    }
};


int main(){
    Solution s;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    int k1 = 4, k2 = 5;
    Node* lcaNode = s.lca(root, k1, k2);
    if (lcaNode) {
        cout << "LCA of " << k1 << " and " << k2 << " is: " << lcaNode->data << endl;
    } else {
        cout << "LCA not found" << endl;
    }

    return 0;
}
