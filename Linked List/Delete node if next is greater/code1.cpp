#include<iostream>


using namespace std;


struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
        Node *compute(Node *head) {
            if (!head || !head->next) return head;
    
            // Reverse the linked list
            Node* prev = NULL;
            Node* curr = head;
            Node* next = NULL;
            while (curr != NULL) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            head = prev;
        
            // Remove nodes that are smaller than the max seen so far
            Node* maxNode = head;
            curr = head;
            prev = NULL;
            while (curr != NULL) {
                if (curr->data >= maxNode->data) {
                    maxNode = curr;
                    prev = curr;
                    curr = curr->next;
                } else {
                    if (prev != NULL) {
                        prev->next = curr->next;
                    }
                    Node* temp = curr;
                    curr = curr->next;
                    delete temp;
                }
            }
        
            // Reverse the list again to restore the original order
            prev = NULL;
            curr = head;
            next = NULL;
            while (curr != NULL) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            head = prev;
        
            return head;
    }
};