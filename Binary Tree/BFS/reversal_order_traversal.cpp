#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

class Solution {
  public:
    vector<int> reverseLevelOrder(Node *root) {
        vector<int> ans;
        if (root == NULL) return ans;
        
        queue<Node*> q;
        stack<int> st;
        
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            for (int i =0; i<size; i++){
                Node * node = q.front();
                q.pop();
                if(node->right != NULL) q.push(node->right);
                if(node->left != NULL) q.push(node->left);
                st.push(node->data);
            }
        }
        
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};