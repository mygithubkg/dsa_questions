#include<iostream>

class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        DLLNode* pre = NULL;
        DLLNode* curr = head;
        DLLNode* nex = NULL;
        
        while (curr){
            nex = curr->next;
            curr->next = pre;
            curr->prev = nex;
            pre = curr;
            curr = nex;
        }
        
        return pre;
    }
};