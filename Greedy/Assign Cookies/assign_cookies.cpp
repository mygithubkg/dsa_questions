#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;



class Solution {
public:
    int maxChildren(vector<int> &greed, vector<int> &cookie) {
        sort(greed.begin(),greed.end());
        sort(cookie.begin(),cookie.end());
        int count = 0;
        int i =0;
        int j = 0;
        // int total_cookie = 0;
        // for (int i: cookie){
        //     total_cookie +=i;
        // }
        
        while (i < greed.size() && j < cookie.size()){
            if (cookie[j] >= greed[i]){
                count ++;
                i++;
            }
            j++;
            
        }
        return count;
    }
};

int main(){
    Solution s;
    vector<int> greed = {1,2,3};
    vector<int> cookie = {1,1};
    cout << s.maxChildren(greed,cookie) << endl; // Output: 1
    return 0;
}