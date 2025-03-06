#include<iostream>
#include<unordered_map>

using namespace std;

/* Link list Node */
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

class Solution {
    public:
      Node *cloneLinkedList(Node *head) {
          if (!head) return head;
          
          unordered_map<Node*,Node*> mpp;
          
          Node* newhead = new Node(head->data);
          Node* old = head;
          Node* newl = newhead;
          mpp[old] = newl;
          
          
          while (old->next != NULL){
              Node* copyElement = new Node(old->next->data);
              newl->next = copyElement;
              newl = newl->next;
              old = old->next;
              mpp[old] = copyElement;
          }
          
          old = head;
          newl = newhead;
          while (old != NULL){
              if (old->random != nullptr){
                  newl->random = mpp[old->random];
              }
              
              old = old->next;
              newl = newl->next;
          }
          
          return newhead;
          
      }
  };