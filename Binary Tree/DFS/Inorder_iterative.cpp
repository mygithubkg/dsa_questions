#include<iostream>
#include<vector>
#include<stack>


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

vector<int> inorder(Node* root){
    vector<int> ans;
    stack<Node*> st;
    Node* curr = root;
    while (true){
        if (curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
        else{
            if (st.empty()== true){
                break;
            }
            else{
                curr = st.top();
                st.pop();
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return ans;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans = inorder(root);
    for (auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}
