#include<iostream>
#include <unordered_map>

using namespace std;

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
    Node *removeDuplicates(Node *head) {
        unordered_map <int,bool> mpp;

        Node* prev = head;
        Node* curr = head->next;
        mpp[head->data] = true;
        while(curr){
            if(mpp[curr->data]){
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else{
                mpp[curr->data] = true;
                prev = prev->next;
                curr = curr->next;
            }
        }
        return head;
    }
};