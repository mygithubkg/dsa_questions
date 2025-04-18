#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
    private:
        bool detect(int src, vector<vector<int>>& adj, vector<int>& vis) {
            vis[src] = 1;
            queue<pair<int, int>> q; // Pair of (node, parent)
            q.push({src, -1});
            
            while (!q.empty()) {
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();
                
                for (auto neighbor : adj[node]) {
                    if (!vis[neighbor]) {
                        vis[neighbor] = 1;
                        q.push({neighbor, node});
                    } else if (neighbor != parent) {
                        // Cycle found
                        return true;
                    }
                }
            }
            return false;
        }
    
    public:
        bool isCycle(int V, vector<vector<int>>& edges) {
            // Create an adjacency list
            vector<vector<int>> adj(V);
            for (auto edge : edges) {
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }
    
            // Visited array to track visited nodes
            vector<int> vis(V, 0);
    
            // Check for cycles in each component
            for (int i = 0; i < V; i++) {
                if (!vis[i]) {
                    if (detect(i, adj, vis)) {
                        return true;
                    }
                }
            }
            return false;
        }
    };

    int main(){
        Solution obj;
        vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}}; // Example edges
        int V = 3; // Number of vertices
        cout << (obj.isCycle(V, edges) ? "Cycle detected" : "No cycle detected") << endl;
        return 0;
    }