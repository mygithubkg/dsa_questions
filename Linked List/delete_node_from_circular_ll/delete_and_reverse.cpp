#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    struct Node *next;


    Node(int val){
        data = val;
        next = NULL;
    }
};

class Solution{
    public: 
        Node* reverse(Node* head) {
        if (!head || head->next == head) return head;
        
        Node* prev = NULL;
        Node* curr = head;
        Node* nex;
        Node* tail = head;
        
        
        do{
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        while(curr != head);
        
        curr->next = prev;
        head = prev;
        return head;
    }

    // Function to delete a node from the circular linked list
    Node* deleteNode(Node* head, int key) {
        if(!head)return head;
        Node *i=head;
        while(i->data!=key){
            i=i->next;
            if(i==head)break;
        }
        if(i->data==key){
            i->data=i->next->data;
            i->next=i->next->next;
        }
        return head;
    }
};
