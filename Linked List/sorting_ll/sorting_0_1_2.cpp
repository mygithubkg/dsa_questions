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
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
        Node* curr = head;
        int count_0, count_1,count_2 = 0;
        
        while (curr){
            if (curr->data == 0){
                count_0+=1;
            }else if (curr->data == 1){
                count_1 +=1;
            }else{
                count_2 +=1;
            }
            curr = curr->next;
        }
        
        curr = head;
        
        while (count_0 != 0){
            curr->data = 0;
            curr = curr->next;
            count_0--;
        }
        
        while (count_1 != 0){
            curr->data = 1;
            curr = curr->next;
            count_1--;
        }
        while (count_2 != 0){
            curr->data = 2;
            curr = curr->next;
            count_2--;
        }
        
        return head;
    }
};