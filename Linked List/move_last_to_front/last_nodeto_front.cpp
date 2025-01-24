#include<iostream>

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution {
  public:
    Node *moveToFront(Node *head) {
        if (!head || !head->next) return head;
        Node* curr = head;
        Node* prev = NULL;
        while(curr->next){
            prev = curr;
            curr= curr->next;
        }
        if (prev) prev->next = NULL;
        
        curr->next = head;
        head = curr;
        return head;
    }
};