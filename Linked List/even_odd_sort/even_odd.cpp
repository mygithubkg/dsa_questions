#include<iostream>

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
    Node* divide(Node* head) {
        Node* curr = head;
        Node* evenstart = nullptr;
        Node* evenend = nullptr;
        Node* oddstart = nullptr;
        Node* oddend = nullptr;
        
        while (curr){
            if (curr->data % 2 == 0){
                if (evenstart == nullptr){
                    evenstart = curr;
                    evenend = evenstart;
                }else{
                    evenend ->next = curr;
                    evenend = evenend->next;
                }
            }else{
                if (oddstart == nullptr){
                    oddstart = curr;
                    oddend = oddstart;
                }else{
                    oddend->next = curr;
                    oddend = oddend->next;
                }
            }
            curr = curr->next;
        }
        
        if (evenstart == nullptr){
            return oddstart;
        }
        if (oddstart == nullptr){
            return evenstart;
        }
        
        evenend->next = oddstart;
        oddend->next = NULL;
        
        
        return evenstart;
    }
};