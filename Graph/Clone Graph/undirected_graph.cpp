#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

struct Node {
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
  public:
    Node* cloneGraph(Node* node) {
         if (node == nullptr) return nullptr;

        unordered_map<Node*, Node*> mp;
        Node* newNode = new Node(node->val);
        mp[node] = newNode;

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();

            for (Node* neighbor : cur->neighbors) {
                if (mp.find(neighbor) == mp.end()) {
                    mp[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                mp[cur]->neighbors.push_back(mp[neighbor]);
            }
        }

        return newNode;
        
    }
};

int main(){
    // Example usage
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);
    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);

    Solution sol;
    Node* clonedGraph = sol.cloneGraph(node1);

    // Output the cloned graph (for testing)
    cout << "Cloned graph nodes:" << endl;
    for (Node* neighbor : clonedGraph->neighbors) {
        cout << neighbor->val << " ";
    }
    
    return 0;
}