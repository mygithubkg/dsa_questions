#include<iostream>
#include<unordered_set>

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

Node *intersectPoint(Node *head1, Node *head2) {
    unordered_set<Node *> visitedNodes;

    // Traverse the first list and store all nodes in a set
    Node *curr1 = head1;
    while (curr1 != nullptr) {
        visitedNodes.insert(curr1);
        curr1 = curr1->next;
    }

    // Traverse the second list and check if any node is in the set
    Node *curr2 = head2;
    while (curr2 != nullptr) {
        if (visitedNodes.find(curr2) != visitedNodes.end()) {
            
              // Intersection point found
            return curr2;
        }
        curr2 = curr2->next;
    }

    return nullptr;
}