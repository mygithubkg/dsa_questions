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
        left = NULL;
        right = NULL;
    }   
};


vector<int> postorder(Node* root){
    vector<int> ans;
    stack<Node*> st;
    Node* curr = root;
    
    if (curr == NULL) return ans;

    st.push(curr);
    while(!st.empty()){
        curr = st.top();
        st.pop();
        ans.insert(ans.begin(), curr->data);

        if (curr->left != NULL) st.push(curr->left);
        if (curr->right != NULL) st.push(curr->right);
    }
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans = postorder(root);
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}


// using two stacks

vector<int> postorder2stack(Node* root){
    vector<int> ans;
    stack<Node*> st1;
    stack<Node*> st2;
    Node* curr = root;
    
    if (curr == NULL) return ans;

    st1.push(curr);
    while(!st1.empty()){
        curr = st1.top();
        st1.pop();
        st2.push(curr);

        if (curr->left != NULL) st1.push(curr->left);
        if (curr->right != NULL) st1.push(curr->right);
    }

    while(!st2.empty()){
        ans.push_back(st2.top()->data);
        st2.pop();
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

    vector<int> ans = postorder2stack(root);
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}