#include<iostream>
#include<vector>
#include<queue>

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
    vector<int> rightView(Node *root) {
        vector<int> ans; 
        if (root == NULL) return ans;
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()){
            int n = q.size();
            
            for (int i =0; i < n; i++){
                Node* node = q.front();
                q.pop();
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
                if (i==n-1){
                    ans.push_back(node -> data);
                }
            }
        }
        return ans;
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
    vector<int> ans = obj.rightView(root);
    for (auto i: ans){
        cout<<i<<" ";
    }
    return 0;   
}