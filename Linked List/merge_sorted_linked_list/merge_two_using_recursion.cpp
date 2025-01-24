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
    Node* sortedMerge(Node* head1, Node* head2) {
        if (!head1) return head2;
        if (!head2) return head1;
        // COMPARE VALUE ASSIGN HEAD AND DO RECURSION AGAIN
        if (head1->data < head2->data){
            head1->next = sortedMerge(head1->next, head2);
            return head1;
        }else{
            head2->next = sortedMerge(head1, head2->next);
            return head2;
        }
    }
};