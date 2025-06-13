#include<iostream>
#include<queue>
#include<unordered_set>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
  public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string>& wordList) {
        // code here
        // Now it stores vector of strings for sequences
        queue<vector<string>> q;
        q.push({beginWord});
        
        // Set for checking the word
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        vector<vector<string>> ans ;
        
        unordered_map<string,int> mpp;
        mpp[beginWord] = 1;
        
        vector<string> levelWise;
        levelWise.push_back(beginWord);
        int level = 0;
        
        while(!q.empty()){
            // Now it has a vector
            vector<string> vecWord = q.front();
            q.pop();
            
            //  If complete level is done then only we remove it from set or else not
            if (vecWord.size() > level){
                level++;
                for (auto it : levelWise){
                    st.erase(it);
                }
            }
            
            string word = vecWord.back();
            
            if (word == endWord){
                if (ans.size()==0){
                    ans.push_back(vecWord);
                }
                else if (ans[0].size() == vecWord.size()){
                    ans.push_back(vecWord);
                }
                
            }
            for (int i =0; i < word.size(); i++){
                char original = word[i];
                for (char ch = 'a'; ch<='z'; ch++){
                    word[i] = ch;
                    if (st.count(word)>0){
                        vecWord.push_back(word);
                        q.push({vecWord});
                        levelWise.push_back(word);
                        vecWord.pop_back();
                    }
                }
                word[i] = original;
            }
            
           
            
        }
         return ans;
    }
};

int main(){
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    
    vector<vector<string>> result = sol.findSequences(beginWord, endWord, wordList);
    
    for (const auto& sequence : result) {
        for (const auto& word : sequence) {
            cout << word << " ";
        }
        cout << endl;
    }
    
    return 0;
    
}