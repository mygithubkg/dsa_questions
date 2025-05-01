#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
    
      bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathvis){
        vis[node] = 1;
        pathvis[node] = 1;
        
        
        for (auto it : adj[node]){
            // If node is not previously visited
            if (!vis[it]){
                if (dfs(it, adj, vis, pathvis)) return true;
            }
            // if vis and path was also same and not different then it is a loop 
            else if (pathvis[it]) return true;
        }
        
        // making path nodes 0 while backtracking to allow having a new path 
        pathvis[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        // making adj list 
        vector<vector<int>> adj(V);
        for (auto it: edges){
            adj[it[0]].push_back(it[1]);
            
        }
        
        vector<int> vis(V,0);
        vector<int> pathvis(V,0);
        
        
        for (int i = 0; i <V; i++){
            if (dfs(i, adj,vis,pathvis)) return true;
        }
        
        return false;
        
    }
};


int main(){
    Solution obj;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}}; // Example edges
    int V = 3; // Number of vertices
    cout << (obj.isCyclic(V, edges) ? "Cycle detected" : "No cycle detected") << endl;
    return 0;
}