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
    void reverse(Node* &head){
        Node* prev = NULL;
        Node* curr = head;
        Node* nex = NULL;
        
        while (curr){
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        head = prev;
    }
    
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        if (!head || !head->next) return true;

        // Find the middle of the list
        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half
        Node* secondHalf = slow;
        reverse(secondHalf);

        // Check palindrome
        Node* firstHalf = head;
        Node* tempSecondHalf = secondHalf;
        bool isPalin = true;

        while (tempSecondHalf) {
            if (firstHalf->data != tempSecondHalf->data) {
                isPalin = false;
                break;
            }
            firstHalf = firstHalf->next;
            tempSecondHalf = tempSecondHalf->next;
        }

        // Re-reverse the second half to restore the list
        reverse(secondHalf);

        return isPalin;
    
    }
};