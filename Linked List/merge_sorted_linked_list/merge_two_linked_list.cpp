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
        Node* curr1 = head1;
        Node* curr2 = head2;
        Node* ans = NULL;
        Node* head = NULL;
        if (curr1->data > curr2->data){
            ans = curr2;
            head = ans;
            curr2 = curr2->next;
        }else{
            ans = curr1;
            head = ans;
            curr1 = curr1->next;
        }
        while(curr1 && curr2){
            if (curr1->data > curr2->data){
                ans->next = curr2;
                ans = curr2;
                curr2 = curr2->next;
            }else{
                ans->next = curr1;
                ans = curr1;
                curr1 = curr1->next;
            }
        }
        while (curr1) {
            ans->next = curr1;
            ans = curr1;
            curr1 = curr1->next;
        }

    
        while (curr2) {
            ans->next = curr2;
            ans = curr2;
            curr2 = curr2->next;
        }
        
        return head;
    }
};