#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Solution {
    public:

    void dfsMethod(int node, vector<vector<int>> adj, vector<int> &vis, vector<int> &ans){
        vis[node] = 1;
        ans.push_back(node);
        for (auto it : adj[node]){
            if(!vis[it]) {
                dfsMethod(it,adj,vis,ans);
            }
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0);
        vector<int> ans;
        dfsMethod(0,adj,vis, ans);
        return ans;
        
    }
};
int main(){
    Solution s;
    vector<vector<int>> adj = {
        {1, 2},
        {0, 3},
        {0, 3},
        {1, 2}
    };
    
    vector<int> result = s.dfs(adj);
    
    for (int i : result) {
        cout << i << " ";
    }
    
    return 0;
}