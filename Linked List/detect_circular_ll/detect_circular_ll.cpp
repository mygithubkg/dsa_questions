#include<iostream>

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};


/* Should return true if linked list is circular, else false */
class Solution {
  public:
    bool isCircular(Node *head) {
        if (!head) return false;
        
        // using slow fast pointer approach to detect loop
        
        Node* slow = head;
        Node* fast = head;
        
        while (fast && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast){
                return true;
            }
        }
        return false;
    }
};