#include<iostream>


using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
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
        head=prev;
        return prev;
    }
    
    Node* addTwoLists(Node* num1, Node* num2) {
        num1 = reverse(num1);
        num2 = reverse(num2);
        Node* ans = new Node(0);
        Node* head = ans;
        int carry = 0;
        while (num1 || num2 || carry){
            int total = carry;
            
            if (num1){
                total += num1->data;
                num1 = num1->next;
            }
            if (num2){
                total += num2->data;
                num2 = num2->next;
            }
            carry = total / 10;
            int sum = total % 10;
            ans->next = new Node(sum);
            ans = ans->next;
        }
                
        head = reverse(head->next);

        while (head && head->data == 0 && head->next) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        return head;
    }
};