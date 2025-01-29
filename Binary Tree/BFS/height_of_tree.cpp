#include<iostream>
#include<queue>


using namespace std;    

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Returns height which is the number of edges
// along the longest path from the root node down 
// to the farthest leaf node.
int height(Node *root) {
    if (root == nullptr)
        return -1;

    // compute the height of left and right subtrees
    int lHeight = height(root->left);
    int rHeight = height(root->right);

    return max(lHeight, rHeight) + 1;
}
int height2(Node* root) {
    if (!root) return 0;

    // Initializing a variable to count 
    // the height of the tree
    int height = 0;

    queue<Node*> q;

    // Pushing the first level element 
    // along with nullptr
    q.push(root);
    q.push(nullptr);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        // When nullptr is encountered, 
        // increment the height
        if (curr == nullptr) {
            height++;

            // If queue still has elements left, 
            // push nullptr again to the queue
            if (!q.empty()) {
                q.push(nullptr);
            }
        } 
        else {
          
            // If nullptr is not encountered, 
            // keep moving
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
    return height - 1;
}

int main() {
  
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    
    cout << height(root);
    
    return 0;
}