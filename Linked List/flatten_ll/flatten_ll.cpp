#include<iostream>

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};


class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node* merge(Node* l1,Node* l2){
        Node* ans = new Node(-1);
        Node* curr = ans;
        
        while (l1 && l2){
            
            if (l1->data > l2->data){
                curr->bottom = new Node(l2->data);
                l2 = l2->bottom;
            }else{
                curr->bottom = new Node(l1->data);
                l1 = l1->bottom;
            }
            curr->next = NULL;
            curr = curr->bottom;
        }
        
        while (l1){
            curr->bottom = new Node(l1->data);
            l1 = l1->bottom;
            curr->next = NULL;
            curr = curr->bottom;
        }
        
        while (l2){
            curr->bottom = new Node(l2->data);
            l2 = l2->bottom;
            curr->next = NULL;
            curr = curr->bottom;
        }
        
        return ans->bottom;
        
    }

    
    
    
    Node *flatten(Node *root) {
        if (!root || !root->next){
            return root;
        }
        Node *mergehead = flatten(root->next);
        return merge(root, mergehead);

        
    }
};