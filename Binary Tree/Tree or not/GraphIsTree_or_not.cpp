#include<iostream>
#include<vector>

using namespace std;

void dfsCheck(vector<int> &vis, vector<vector<int>> &addj, int node) {
    vis[node] = 1; // Mark the current node as visited
    
    for (auto neighbor : addj[node]) {
        if (!vis[neighbor]) { // Visit unvisited neighbors
            dfsCheck(vis, addj, neighbor);
        }
    }
}

// Function to check if the graph is a tree
int isTree(int n, int m, vector<vector<int>> &adj) {
    // Condition 1: Number of edges must be exactly n-1
    if (m != n - 1) {
        return 0; // Not a tree
    }
    vector<vector<int>> addj(n);
    for (auto edge : adj) {
        int u = edge[0];
        int v = edge[1];
        addj[u].push_back(v);
        addj[v].push_back(u);
    }

    vector<int> vis(n, 0); // Visited array to track visited nodes

    // Condition 2: Check for connectivity
    dfsCheck(vis, addj, 0); // Start DFS from node 0

    // Ensure all nodes are visited
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            return 0; // Not a tree, graph is not connected
        }
    }

    // If all conditions are satisfied, it's a tree
    return 1;
};

int main(){
    int n, m; // Number of nodes and edges
    cin >> n >> m;
    vector<vector<int>> adj(m, vector<int>(2)); // Adjacency list for edges
    for (int i = 0; i < m; i++) {
        cin >> adj[i][0] >> adj[i][1]; // Input edges
    }
    
    cout << isTree(n, m, adj) << endl; // Output whether the graph is a tree or not
    return 0;
}

