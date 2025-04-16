#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
      void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
          visited[node] = true;
          for (int i = 0; i < adj.size(); i++) {
              if (adj[node][i] == 1 && !visited[i]) {
                  dfs(i, adj, visited);
              }
          }
      }
  
      int numProvinces(vector<vector<int>> adj, int V) {
          vector<bool> visited(V, false);
          int provinces = 0;
      
          for (int i = 0; i < V; i++) {
              if (!visited[i]) {
                  provinces++;
                  dfs(i, adj, visited);
              }
          }
      
          return provinces;
      }
  };

  int main(){
      Solution s;
      vector<vector<int>> adj = {
          {1, 1, 0},
          {1, 1, 0},
          {0, 0, 1}
      };
      int V = 3;
  
      int result = s.numProvinces(adj, V);
  
      cout << "Number of Provinces: " << result << endl;
  
      return 0;
  }