#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> ans;
    	if (!root) return ans;
    	
    	queue<Node*> q;
    	q.push(root);
    	
    	bool lefttoright = true;
    	
    	while(!q.empty()){
    	    int size = q.size();
    	    vector<int> level(size);
    	    
    	    for (int i=0; i<size; i++){
	            Node* node = q.front();
	            q.pop();
	            
	            int index = lefttoright ? i : size - 1 - i;
                level[index] = node->data;
	            if (node->left) q.push(node->left);
	            if (node->right) q.push(node->right);
	        }
	        
    	    ans.insert(ans.end(), level.begin(), level.end());
    	    lefttoright = !lefttoright;
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
    vector<int> ans = obj.zigZagTraversal(root);
    for (auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}