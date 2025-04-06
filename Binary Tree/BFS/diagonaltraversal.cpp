#include<iostream>
#include<unordered_map>
#include<vector>


using namespace std;

struct Node
{
    int data;
    Node* left, * right;
}; 

class Solution {
  public:
    // Function to take diagonal elements
    void diagonalRec(Node* root, int level, unordered_map<int, vector<int>> &leveldata){
        if (root== NULL){
            return;
        }
        
        // If left node is given a level which is added to leveldata
        // and right node is given the same level as root
        leveldata[level].push_back(root->data);
        
        diagonalRec(root->left, level+1, leveldata);
        diagonalRec(root->right, level, leveldata);
        
        
    }
    
    vector<int> diagonal(Node *root) {
        vector<int> ans; 
        unordered_map<int, vector<int>> leveldata;
        int level = 0;
        if (root == NULL) return ans;
        
        diagonalRec(root, 0, leveldata);
        
        level = 0; 
        
        while (leveldata.find(level) != leveldata.end()){
            vector<int> temp = leveldata[level];
            for (int i = 0; i < temp.size(); i++){
                ans.push_back(temp[i]);
            }
            level++;
        }
        return ans;
    }
};


int main(){
    Node* root = new Node();
    root->data = 1;
    root->left = new Node();
    root->left->data = 2;
    root->right = new Node();
    root->right->data = 3;
    root->left->left = new Node();
    root->left->left->data = 4;
    root->left->right = new Node();
    root->left->right->data = 5;
    
    Solution s;
    vector<int> result = s.diagonal(root);
    
    for (int i : result) {
        cout << i << " ";
    }
    
    return 0;
}