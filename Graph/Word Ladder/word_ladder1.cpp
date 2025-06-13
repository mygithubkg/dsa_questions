#include<iostream>
#include<queue>
#include<unordered_set>
#include<string>

using namespace std;
class Solution {
  public:
    int wordLadderLength(string startWord, string targetWord,
                         vector<string>& wordList) {
        // Code here
        // We initialize a queue for making the correct order
        
        queue<pair<string, int>> q;
        q.push({startWord,1});
        
        // Set for storing all words in the wordList
        // We use an unordered_set for O(1) average time complexity for lookups
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(startWord);
        
        // If the target word is not in the wordList, return 0
        // checking until queue is not empty
        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            
            // if found returns step size 

            if (word == targetWord) return step;

            // We iterate through each character of the word
            // and try to replace it with every letter from 'a' to 'z'
            for (int i = 0; i< word.size(); i++){
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if (st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word,step+1});
                    }
                }
                // Restore the original character after trying all replacements
                // This is important to avoid modifying the original word
                word[i] = original;
            }
        }
        
        return 0;
    }
};


int main(){
    Solution sol;
    string startWord = "hit";
    string targetWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    
    int result = sol.wordLadderLength(startWord, targetWord, wordList);
    cout << "The length of the shortest transformation sequence is: " << result << endl;

    return 0;
}