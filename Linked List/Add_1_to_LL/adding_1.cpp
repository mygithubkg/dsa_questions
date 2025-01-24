#include <iostream>


struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    void reverse(Node* &head){
        Node* prev = NULL;
        Node* curr = head;
        Node* nex = NULL;
        while(curr){
            nex= curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        head = prev;
    }
    
    Node* addOne(Node* head) {
        if (head == NULL) return new Node(1); 
        reverse(head);
        Node* prev = NULL;
        Node* curr = head;
        
        while (curr != NULL) {
            if (curr->data < 9) {
                curr->data += 1;
                reverse(head);
                return head;
            } else {
                curr->data = 0;
                prev = curr;
                curr = curr->next;
            }
        }
        
        reverse(head);
        if (prev != NULL) {
            Node* newNode = new Node(1);
            newNode->next = head;
            head = newNode;
        }
        
        return head;
    }
 
};