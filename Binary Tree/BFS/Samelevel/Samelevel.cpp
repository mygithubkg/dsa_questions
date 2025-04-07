#include<iostream>
#include<set>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};


class Solution {
  public:
    /*You are required to complete this method*/
    
    void checkatsamelevel(Node*root, int level,set<int> &levelData){
        if (!root) return;
        
        if (!root->left && !root->right){
            levelData.insert(level);
        }
        
        if (root->left) checkatsamelevel(root->left, level+1, levelData);
        if (root->right) checkatsamelevel(root->right, level+1, levelData);
    }
    
    bool check(Node *root) {
        int level = 0;
        set<int> levelData;
        
        
        checkatsamelevel(root,0,levelData);
        
        if (levelData.size() > 1){
            return false;
        }
        
        return true;
        
    }
};

int main() {
    // Example usage of the check function
    Node* root = new Node{1, new Node{2}, new Node{3}};
    Solution sol;
    cout << (sol.check(root) ? "Yes" : "No") << endl; // Output: No

    return 0;
}