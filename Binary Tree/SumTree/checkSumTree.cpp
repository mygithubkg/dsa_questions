#include<iostream>


using namespace std; 

struct Node
{
    int data;
    Node* left, * right;
};

class Solution{
    public:
    int checkSumtree(Node* root, bool &ans){
        if (!root) return 0;
        if (!root->left && !root->right) return root->data;

        int leftsum = checkSumtree(root->left, ans);
        int rightsum = checkSumtree(root->right, ans);

        if (leftsum + rightsum != root->data){
            ans = false;
        }

        return leftsum + rightsum + root->data;
    }

    bool isSumTree(Node* root){
        bool ans = true;
        checkSumtree(root, ans);
        return ans;
    }
};

int main(){
    // Example usage of the isSumTree function
    Node* root = new Node{26, new Node{10, new Node{4}, new Node{6}}, new Node{3}};
    Solution sol;
    cout << (sol.isSumTree(root) ? "Yes" : "No") << endl; // Output: Yes

    return 0;
}