#include<iostream>



using namespace std;

    struct Node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;


class Solution {
  public:
    Node* reverse(Node *&head){
        Node* prev = NULL;
        Node* curr = head;
        Node* nex = NULL;
        while (curr != NULL){
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
    
    Node* Kthnode(Node* temp, int k){
        k-=1;
        while(temp != NULL && k>0){
            k--;
            temp= temp->next;
        }
        
        return temp;
    }
    Node* kthLast(Node* temp, int k){
        k-=1;
        while(temp->next != NULL && k>0){
            k--;
            temp= temp->next;
        }
        
        return temp;
    }
    
    Node *reverseKGroup(Node *head, int k) {
        Node* temp = head;
        Node* prevnode = NULL;
        while (temp){
            Node* knode = Kthnode(temp,k);
            if (knode == NULL){
                Node* Last = kthLast(temp,k);
                reverse(temp);
                if (prevnode) prevnode->next = Last;
                break;
            }
            Node* nexnode = knode->next;
            knode->next = NULL;
            reverse(temp);
            if (temp==head){
                head = knode;
            }else{
                prevnode->next = knode;
            }
            prevnode = temp;
            temp= nexnode;
        }
        return head;
    }
};