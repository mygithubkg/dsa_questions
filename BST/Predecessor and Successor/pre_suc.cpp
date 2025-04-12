#include<iostream>

using namespace std;    

struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};


// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        Node* node1 =root;
        // ceil approach
        while (node1){
            if (key >= node1->key){
                node1 = node1->right;
            }else{
                suc = node1;
                node1 = node1->left;
            }
        }
        
        Node* node2 =root;
        // floor approach
        while (node2){
            if (key <= node2->key){
                node2 = node2->left;
            }else{
                pre = node2;
                node2 = node2->right;
            }
        }
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
    
    int key = 65;
    Node* pre = NULL;
    Node* suc = NULL;
    
    s.findPreSuc(root, pre, suc, key);
    
    if (pre) cout << "Predecessor: " << pre->key << endl;
    else cout << "No Predecessor" << endl;
    
    if (suc) cout << "Successor: " << suc->key << endl;
    else cout << "No Successor" << endl;
    
    return 0;
}