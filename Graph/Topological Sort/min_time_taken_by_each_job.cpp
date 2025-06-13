#include<iostream>
#include<queue>
#include<vector>

using namespace std;


class Solution {
  public:
    vector<int> minimumTime(int n, vector<vector<int>> &edges, int m) {
        // code here
        vector<vector<int>> adj(n+1);
        vector<int> job (n+1,0);
        
        for (auto it: edges){
            adj[it[0]].push_back(it[1]);
        }
        
        queue<int> q;
        
        // creating in degree for them 
        vector<int> inDegree(n+1,0);
        for (int i = 1; i <=n; i++ ){
            for (auto j: adj[i]){
                inDegree[j]++;
            }
        }
        
        for (int i = 1; i<=n; i++){
            if (inDegree[i]==0){
                q.push(i);
                // Can be completed now so update it's time 
                job[i] = 1;
            }
        }
        
        
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for (auto it: adj[node]){
                inDegree[it]--;
                if (inDegree[it]==0){
                    job[it] = max(job[it],job[node]) +1;
                    q.push(it);
                }
            }
            
        }
        
        return vector<int>(job.begin() + 1, job.end());
    }
};

int main() {
    Solution sol;
    int n = 6; // Number of jobs
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 4}, {3, 4}, {4, 5}, {5, 6}};
    int m = 2; // Not used in this context

    vector<int> result = sol.minimumTime(n, edges, m);
    
    for (int time : result) {
        cout << time << " ";
    }
    cout << endl;

    return 0;
}