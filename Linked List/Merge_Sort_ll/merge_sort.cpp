#include<iostream>


struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    // Function to sort the given linked list using Merge Sort.
    
    Node* findmiddle(Node* head){
        Node* slow = head;
        // One pointer forward to have first middle in case of even
        Node* fast = head->next;
        Node* curr = head;
        while (fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            curr = curr->next;
        }
        return slow;
    }
    
    
    Node* merge2(Node* first, Node* second){
        Node* ans = new Node(-1);
        Node* curr = ans;
        
        while (first != NULL && second!= NULL){
            if (first->data > second->data){
                curr->next = second;
                second = second->next;
            }else{
                curr->next = first;
                first = first->next;
            }
            curr = curr->next;
        }
        if (first) curr->next = first;
        else curr->next = second;
        
        return ans->next;
    }
    
    Node* mergeSort(Node* head) {
        
        if (head == NULL || head->next == NULL) return head;
        
        Node* middle = findmiddle(head);
        
        Node* righthead = middle->next;
        middle->next = NULL;
        
        Node* lefthead = head;
        
        lefthead = mergeSort(lefthead);
        righthead = mergeSort(righthead);
        return merge2(lefthead,righthead);
        
    }
};

int main(){
    Node* head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(15);
    Solution obj;
    Node* newhead = obj.mergeSort(head);
    while (newhead != NULL){
        std::cout<<newhead->data<<" ";
        newhead = newhead->next;
    }
    return 0;
}
