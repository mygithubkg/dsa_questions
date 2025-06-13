#include<iostream>
#include<stack>
#include<vector>


using namespace std;

class Solution {
  public:
  
    // Function to perform DFS and fill the stack
    void dfs(int n, stack<int> &st, vector<vector<int>> &adj, vector<int> &vis){
        vis[n] = 1;
        for (auto i : adj[n]){
            if (!vis[i] == 1){
                dfs(i,st,adj, vis);
            }
        }
        // After visiting all the adjacent nodes, push the current node onto the stack
        // This ensures that the node is processed after all its dependencies
        st.push(n);  
            
    }

    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        
        vector<vector<int>> adj(V); 
        // creating adj edges
        for (auto it: edges){
            adj[it[0]].push_back(it[1]);
        }
        
        // stack for storing the result 
        stack <int> st;
        int n = adj.size();
        
        vector<int> ans; 
        
        vector<int> vis(n,0);
        
        for (int i = 0; i < n; i++){
            if (!vis[i]==1){
                dfs(i,st,adj,vis);
            }
        }
        
        while (!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
        
    }
};

int main(){
    Solution sol;
    int V = 6;
    vector<vector<int>> edges = {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};
    
    vector<int> result = sol.topoSort(V, edges);
    
    cout << "Topological Sort: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;   
}