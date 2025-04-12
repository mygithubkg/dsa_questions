#include<iostream>


using namespace std;



// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution {
    public:
      Node* LCA(Node* root, Node* n1, Node* n2) {
          if (!root) return root;
          
          while (root){
              // if less than on left side
             if (root->data > n1->data && root->data > n2->data)
              root = root->left;
  
          // If both n1 and n2 are greater than root,
          // then LCA lies in right
          else if (root->data < n1->data && root->data < n2->data)
              root = root->right;
          
          // Else Ancestor is found
          else
              break;
          }
          return root;
      }
  
  };
  

  int main (){
        Solution s;
        Node* root = new Node(20);
        root->left = new Node(10);
        root->right = new Node(30);
        root->left->left = new Node(5);
        root->left->right = new Node(15);
        root->right->left = new Node(25);
        root->right->right = new Node(35);
    
        Node* n1 = root->left; // 10
        Node* n2 = root->right; // 30
    
        Node* lcaNode = s.LCA(root, n1, n2);
        if (lcaNode) {
            cout << "LCA of " << n1->data << " and " << n2->data << " is: " << lcaNode->data << endl;
        } else {
            cout << "LCA not found." << endl;
        }
  }