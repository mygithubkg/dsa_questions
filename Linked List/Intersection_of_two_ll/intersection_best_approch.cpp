#include<iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;
    
        Node(int x) {
            data = x;
            next = NULL;
        }
    };
    
    class Solution {
      public:
        // Function to find intersection point in Y shaped Linked Lists.
        int getCount(Node* head){
            Node* curr = head;
            int count = 0;
            while (curr){
                count++;
                curr = curr->next;
            }
        }
        Node* intersectdiff(int diff, Node* head1,Node* head2){
            Node* curr1 = head1;
            Node* curr2 = head2;
            
            for (int i =0; i <diff; i++){
                if (curr1 == nullptr)
                return nullptr;
                curr1 = curr1->next;
            }
            
            while (curr1 && curr2){
                if (curr1 == curr2){
                    return curr1;
                }
                curr1 = curr1->next;
                curr2 = curr2->next;
            }
            
            return nullptr;
        }
        Node* intersectPoint(Node* head1, Node* head2) {
            
            int len1 = getCount(head1);
            int len2 = getCount(head2);
            
            if (len1 > len2){
                int diff = len1 - len2;
                return intersectdiff(diff, head1, head2);
            }else{
                return intersectdiff(len2-len1, head2, head1);
            }
            
        }
    };
    