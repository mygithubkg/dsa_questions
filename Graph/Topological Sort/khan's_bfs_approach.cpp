#include<iostream>
#include<queue>
#include<vector>

using namespace std;


// kahn's algorithm for topological sorting using BFS

class Solution{
    public:
        vector<int> toposort(int V, vector<vector<int>>& edges) {
            // Create adjacency list
            vector<vector<int>> adj(V);
            for (auto it : edges) {
                adj[it[0]].push_back(it[1]);
            }

            // Calculate in-degrees
            vector<int> inDegree(V, 0);
            for (int i = 0; i < V; i++) {
                for (auto j : adj[i]) {
                    inDegree[j]++;
                }
            }

            // Initialize queue and result vector
            queue<int> q;
            for (int i = 0; i < V; i++) {
                if (inDegree[i] == 0) {
                    q.push(i);
                }
            }

            vector<int> ans;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                ans.push_back(node);

                // Decrease in-degree of adjacent nodes
                for (auto it : adj[node]) {
                    inDegree[it]--;
                    if (inDegree[it] == 0) {
                        q.push(it);
                    }
                }
            }

            return ans;
        }
};


int main() {
    Solution sol;
    int V = 6;
    vector<vector<int>> edges = {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};
    
    vector<int> result = sol.toposort(V, edges);
    
    cout << "Topological Sort: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}   
