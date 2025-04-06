#include<iostream>
#include<string>
#include<algorithm>
#include<set>
#include<vector>


using namespace std; 

// O(NlogN ) time complexity and O(N) space complexity

// class Solution {
//     public:
//     string swapchar(string str){
//         set<char> characters;
//         for (char c : str) {
//             characters.insert(c);
//         }

//         for (int i = 0; i <str.length(); i++){
//             characters.erase(str[i]);
//             if (!characters.empty() && *characters.begin() < str[i]){
//                 char toSwap = *characters.begin();
//                 char current = str[i];

//                 for (int j = 0; j < str.length(); j++){
//                     if (str[j] == current){
//                         str[j] = toSwap;
//                     } else if (str[j] == toSwap){
//                         str[j] = current;
//                     }
//                 }
//                 break;
//             }

//         }
//         return str;
//     }
// };

// O(N) time complexity and O(1) space complexity

class Solution{
    public:
    string swapChar(string str){
        vector<int> firstIndex(26, -1); // There are 26 letters in the alphabet

    for (int i = 0; i < str.length(); i++) {
        if (firstIndex[str[i] - 'a'] == -1) {
            firstIndex[str[i] - 'a'] = i; // Save the first occurrence
        }
    }

    // Traverse the string to find a smaller lexicographical character to swap
    for (int i = 0; i < str.length(); i++) {
        // Look for a smaller character appearing later
        for (int ch = 0; ch < (str[i] - 'a'); ch++) {
            if (firstIndex[ch] > i) {
                // Swap all occurrences of str[i] with the smaller character
                char currentChar = str[i];
                char charToSwap = 'a' + ch;

                for (int j = 0; j < str.length(); j++) {
                    if (str[j] == currentChar) {
                        str[j] = charToSwap;
                    } else if (str[j] == charToSwap) {
                        str[j] = currentChar;
                    }
                }
                return str; // Return after the first valid swap
            }
        }
    }
    return str;


    }
};

int main(){
    Solution s;
    string str = "dcba";
    cout << s.swapChar(str) << endl; // Output: "abcd"
    return 0;
}