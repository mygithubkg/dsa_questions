#include<iostream>
#include<queue>
#include<map>
#include<vector>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};


class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        vector<int> ans; 
        if (root == NULL) return ans;
        
        queue<pair<Node*,int>> q;
        q.push({root,0});
        
        map<int,int> mpp;
        
        while (!q.empty()){
            auto it = q.front();
            q.pop();
            
            Node* node = it.first;
            int hd = it.second;
            
            if (mpp.find(hd) == mpp.end()){
                mpp[hd] = node->data;
            }
            
            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }
        
        for (auto it : mpp) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};


int main(){
    Node* root = new Node{1, nullptr, nullptr};
    root->left = new Node{2, nullptr, nullptr};
    root->right = new Node{3, nullptr, nullptr};
    root->left->left = new Node{4, nullptr, nullptr};
    root->left->right = new Node{5, nullptr, nullptr};
    root->right->left = new Node{6, nullptr, nullptr};
    root->right->right = new Node{7, nullptr, nullptr};

    Solution obj;
    vector<int> ans = obj.topView(root);
    for (auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}