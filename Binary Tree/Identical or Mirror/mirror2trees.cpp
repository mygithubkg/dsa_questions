#include<iostream>
#include<queue>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        vector<stack<int>> st;
        vector<queue<int>> q;
        
        // Initial storing stacks and queue in empty condition
        
        for (int i = 0; i < n; i++){
            st.push_back(stack<int>());
            q.push_back(queue<int>());
        }
        
        // Filling the values
        
        for (int i= 0; i<2*e; i+=2){
            st[A[i]].push(A[i+1]);
            q[B[i]].push(B[i+1]);
        }
        
        // Checking for mirror
        
        for (int i =1; i<n; i++){
            while (!st[i].empty() && !q[i].empty()){
                int a = st[i].top();
                st[i].pop();
                int b = q[i].front();
                q[i].pop();
    
                if (a != b)
                {
                    return 0;
                }
                }
        }
        
        return 1;
    }
};

int main(){
    int n = 5, e = 4;
    int A[] = {1, 2, 1, 3, 2, 4, 2, 5};
    int B[] = {1, 3, 1, 2, 2, 5, 2, 4};
    
    Solution s;
    cout << s.checkMirrorTree(n, e, A, B) << endl; // Output: 1 (true)
    
    return 0;
}