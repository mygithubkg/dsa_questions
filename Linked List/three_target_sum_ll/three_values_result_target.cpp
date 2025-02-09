#include<iostream>


using namespace std;

class Node {
    public:
        int data;
        Node *next, *prev;
    
        Node(int val) {
            data = val;
            next = nullptr;
            prev = nullptr;
        }
};


// O(n^2) solution without extra space

int countpair(Node* first, Node* last, int value){

    int count = 0;

    while (first != nullptr && last != nullptr && first != last && first != last->next){

        if (first->data + last->data == value){
            count++;
            first = first->next;
            last = last->prev;
        }else if (first->data + last->data < value){
            first = first->next;
        }else{
            last = last->prev;
        }
    }

    return count;
}


int countTriplets(Node* head, int x){
    if (head == nullptr)
    return 0;

    Node  *first, *curr, *last;

    last = head;
    while(last->next != nullptr){
        last = last->next;
    }

    int count = 0;

    for (curr = head; curr != NULL; curr = curr->next){
        first = curr->next;
        count += countpair(first, last, x-curr->data);
    }

    return count;

}


// O(n^3) solution

/*
int countTriplets(Node* head, int x) {
    Node *first, *second, *third;
    int count = 0;
    Node *last = head;
    while (last->next != nullptr) {
        last = last->next;
    }
    for (first = head; first != nullptr; first = first->next) {
        for (second = first->next; second != nullptr; second = second->next) {
            for (third = second->next; third != nullptr; third = third->next) {
                int sum = first->data + second->data + third->data;
                if (sum == x) {
                    count++;
                }
            }
        }
    }
    return count;
}

*/



int main() {

    // Create a hard-coded doubly linked list:
   // 1 <-> 2 <-> 3 <-> 4
   Node *head = new Node(1);
   head->next = new Node(2);
   head->next->prev = head;
   head->next->next = new Node(3);
   head->next->next->prev = head->next;
   head->next->next->next = new Node(4);
   head->next->next->next->prev = head->next->next;

   int x = 8;
   cout << countTriplets(head, x);

   return 0;
}
