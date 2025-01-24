#include<iostream>

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        if (head == nullptr || head->next ==nullptr) return;
        Node* slow = head; 
        Node* fast = head;
        bool iscycle = false;
        
        while (fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                iscycle = true;
                break;
            }
        }
        if (!iscycle) { return;}
        
        Node* prev = nullptr;
        slow = head;
        
        while (slow != fast){
            prev = fast;
            slow = slow->next;
            fast = fast->next;
        }
        
        if (prev != nullptr) { // Make sure we have a valid previous node
            prev->next = nullptr; // Break the cycle
        } else {
            // Edge case handling for when the entire list is a single loop
            while (fast->next != slow) {
                fast = fast->next;
            }
            fast->next = nullptr;
        }
        
    }
};