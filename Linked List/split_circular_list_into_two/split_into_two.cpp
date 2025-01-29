#include<iostream>
#include<bits/stdc++.h>
using namespace std; 


struct Node
{
  int data;
  struct Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
};

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

class Solution {
  public:
    pair<Node *, Node *> splitList(struct Node *head) {
        if (!head) return {nullptr, nullptr};
        
        Node* slow = head;
        Node* fast = head;
        
        while (fast->next != head && fast->next->next != head){
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast->next == head){
            fast->next = slow->next;
        }
        if (fast->next->next == head){
            fast->next->next = slow->next;
        }
        
        Node* head1_ref1 = head;
        Node* head_ref2 = slow->next;
        slow->next = head;
        
        return {head1_ref1, head_ref2};
    }
};