#include<iostream>
#include<vector>
#include<queue>

using namespace std;
// DFS method to detect cycle in an undirected graph

class Solution{
    private:
        bool dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj) {
            vis[node] = 1;
            for (auto neighbor : adj[node]) {
                if (!vis[neighbor]) {
                    if (dfs(neighbor, node, vis, adj)) {
                        return true;
                    }
                } else if (neighbor != parent) {
                    return true; // Cycle detected
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
                    if (dfs(i, -1, vis, adj)) {
                        return true;
                    }
                }
            }
            return false;
        }
};


// instead of taking input from user, we can create a graph using edges

int main(){
    Solution obj;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}}; // Example edges
    int V = 3; // Number of vertices
    cout << (obj.isCycle(V, edges) ? "Cycle detected" : "No cycle detected") << endl;
    return 0;
}