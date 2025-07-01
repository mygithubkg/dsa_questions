#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        vector<pair<int,int>> mst;
        vector<int> vis(V,0);
        int sum = 0;
        
        pq.push({0,0});
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;
            
            if (vis[node] == 1) continue;
            
            vis[node] = 1;
            sum += wt;
            for (auto it : adj[node]){
                int adjNode = it[0];
                int edN = it[1];
                if (!vis[adjNode]){
                    pq.push({edN,adjNode});
                }
            }
        }
        
        return sum;
    }
};

int main(){
    int V = 5;
    vector<vector<int>> adj[V];
    
    // Example graph edges
    adj[0] = {{1, 2}, {3, 6}};
    adj[1] = {{0, 2}, {2, 3}, {4, 5}};
    adj[2] = {{1, 3}, {3, 4}};
    adj[3] = {{0, 6}, {1, 3}, {2, 4}};
    adj[4] = {{1, 5}, {2, 4}};
    
    Solution sol;
    int result = sol.spanningTree(V, adj);
    
    cout << "Sum of weights of edges in the Minimum Spanning Tree: " << result << endl;
    
    return 0;
}