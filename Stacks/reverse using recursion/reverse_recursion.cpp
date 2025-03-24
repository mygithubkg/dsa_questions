#include<iostream>
#include<vector>
#include<stack>

using namespace std;    

class Solution{
    public:
    
    
        void insert_at_bottom(stack<int> &St, int latest){
            if (St.empty()){
                St.push(latest);
                return;
            }
            int topele = St.top();
            St.pop();
            insert_at_bottom(St,latest);
            St.push(topele);
        }
    
    
        void Reverse(stack<int> &St){
            
            if (St.empty()){
                return;
            }
            
            
            int latest = St.top();
            St.pop();
            
            Reverse(St);
            insert_at_bottom(St,latest);
        }
    };
    