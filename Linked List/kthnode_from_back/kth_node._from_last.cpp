#include<iostream>

using namespace std;


class Node{
    public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
    public:
      Node* reverse(Node* &head){
         Node* prev = NULL;
         Node* curr = head;
         Node* nex = NULL;
         while (curr){
             nex = curr->next;
             curr->next = prev;
             prev = curr;
             curr = nex;
         }
         
         return prev;
      }
      int getKthFromLast(Node *head, int k) {
          Node* curr = reverse(head);
          while (k != 1){
              k--;
              curr = curr->next;
              if (curr == NULL || k < 1){
                  return -1;
              }
          }
          
          return curr->data;
      }
  };