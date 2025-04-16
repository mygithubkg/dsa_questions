#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Solution {
    public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        vector<int> ans;
        queue<int> q;
        int n  = adj.size();
        int vis[n] = {0};
        vis[0] = 1;
        
        q.push(0);
        while (!q.empty()){
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for (auto it: adj[node]){
                if (!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
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
    
    vector<int> result = s.bfs(adj);
    
    for (int i : result) {
        cout << i << " ";
    }
    
    return 0;
}