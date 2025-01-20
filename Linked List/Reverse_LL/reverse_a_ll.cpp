#include<iostream>

struct Node
{
    int data;
    struct Node *next;
};      


class Solution {
  public:
    Node* reverseList(struct Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* nex = NULL;
        while (curr != NULL){
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
};