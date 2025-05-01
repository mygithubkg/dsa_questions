#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;


class Solution {
    public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V); 
        
        for (auto &e: edges){
            adj[e[0]].push_back({e[1], e[2]}); // {node,weight}
            adj[e[1]].push_back({e[0], e[2]});
        }
        
        // A mean heap is used 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(V,INT_MAX);
        dist[src] = 0;
        
        pq.push({0,src}); // {dis,node}
        
        while(!pq.empty()){
            int di = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for (auto it : adj[node]) { // `it` is a pair {neighbor, weight}
                int v = it.first;
                int w = it.second;
                if (di + w < dist[v]) {
                    dist[v] = di + w;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return dist;
    }
};


int main(){
    int V = 5; // Number of vertices
    vector<vector<int>> edges = {
        {0, 1, 10},
        {0, 2, 3},
        {1, 2, 1},
        {1, 3, 2},
        {2, 1, 4},
        {2, 3, 8},
        {2, 4, 2},
        {3, 4, 7},
        {4, 3, 9}
    };
    int src = 0; // Starting node

    Solution s;
    vector<int> result = s.dijkstra(V, edges, src);

    for (int i = 0; i < result.size(); i++) {
        cout << "Distance from " << src << " to " << i << " is " << result[i] << endl;
    }

    return 0;
}
  