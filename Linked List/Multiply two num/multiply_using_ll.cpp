#include<iostream>
#include<algorithm>


using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};

/*The method multiplies
two  linked lists l1 and l2
and returns their product*/

/* Multiply contents of two linked lists */
class solution {
  public:
    long long multiplyTwoLists(Node *first, Node *second) {
        string s1 = "";
        string s2 = "";
        
        Node* curr1 = first;
        Node* curr2 = second;
        
        while (curr1){
            s1 += to_string(curr1->data);
            curr1 = curr1->next;
        }
        
        while (curr2){
            s2 += to_string(curr2->data);
            curr2 = curr2->next;
        }
        
        long long num1 = stoll(s1);
        long long num2 = stoll(s2);
        
        return (num1*num2)%1000000007;
    }
};