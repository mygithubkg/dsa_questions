#include<iostream>
#include<stack>
#include<vector>

using namespace std;

//  We will use the DFS approach to find the topological sort of the graph

class Solution {
  public:
  
    void dfs(int n , vector<vector<int>> &adj, stack<int> &st, vector<int> &vis){
        vis[n] = 1;
        
        for (auto it: adj[n]){
            if (!vis[it] == 1){
                dfs(it, adj, st, vis);
            }
        }
        
        st.push(n);
    }
    
    vector<int> findOrder(int n, vector<vector<int>> prerequisites) {
        // code here
        vector<vector<int>> adj(n);
        for (auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(n,0);
        vector<int> ans;
        stack <int> st; 
        
        for (int i =0; i <n; i++){
            if (!vis[i] == 1){
                dfs(i,adj,st,vis);
            }
        }
        
        while (!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
        
    }
};

int main() {
    Solution sol;
    int n = 4; // Number of courses
    vector<vector<int>> prerequisites = {{1, 0}, {2, 1}, {3, 2}}; // Course dependencies
    
    vector<int> result = sol.findOrder(n, prerequisites);
    
    // Print the result
    for (int course : result) {
        cout << course << " ";
    }
    cout << endl;
    
    return 0;
}