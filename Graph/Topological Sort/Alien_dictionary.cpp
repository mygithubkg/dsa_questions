#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;
class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        vector<vector<int>> graph(26);
        
        vector<int> indegree(26,0);
        
        vector<int> exist(26,false);
        
        // Checking which alphabets are used
        for (string word: words){
            for (char ch: word){
                exist[ch-'a'] = true;
            }
        }
        
        // build the graph 
        
        for (int i = 0; i < words.size()-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];
            int len = min(s1.size(),s2.size());
            int j =0;
            
            // if equal
            while(j<len && s1[j]==s2[j]){
                j++;
            }
            if (j < len) {
                graph[s1[j] - 'a'].push_back(s2[j] - 'a');
                indegree[s2[j] - 'a']++;
            } else if (s1.size() > s2.size()) {
                // Invalid input 
                return "";
            }
        }
        
        // Using Topological sort 
        queue<int> q; 
        for (int i =0; i <26; i++){
            if (exist[i] && indegree[i]==0){
                q.push(i);
            }
        }
        
        string ans;
        
        while (!q.empty()){
            int node = q.front();
            q.pop();
            ans +=  char(node + 'a');
            
            for (auto it : graph[node]){
                indegree[it]--;
                if (exist[it] && indegree[it]==0 ){
                    q.push(it);
                }
            }
        }
        
        // Check, there was a cycle or not
        for (int i = 0; i < 26; ++i) {
            if (exist[i] && indegree[i] != 0) {
                return "";
            }
        }
        return ans;
        
    }
    
};

int main() {
    Solution sol;
    vector<string> words = {"baa", "abcd", "abca", "cab", "cad"}; // Example input
    string order = sol.findOrder(words);
    
    if (order.empty()) {
        cout << "Invalid input or cycle detected." << endl;
    } else {
        cout << "The order of characters is: " << order << endl;
    }
    
    return 0;
}

