#include<iostream>
#include<algorithm>

using namespace std;


// Approach 1 - iteratve // Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
    public:
        void reverseArray(int arr[], int n){
            int i=0, j=n-1;
            while (i<=j){
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }
};

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    Solution sol;
    sol.reverseArray(arr, n);
    
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}

// Aprroach 1 - Recursive method // Time Complexity: O(n)
// Space Complexity: O(n) - due to recursion stack

// class Solution {
//     public:
//         void reverseArray(int arr[], int start, int end) {
//             if (start >= end) return;    
//             swap(arr[start], arr[end]);
//             reverseArray(arr, start + 1, end - 1);
//         }
// };
