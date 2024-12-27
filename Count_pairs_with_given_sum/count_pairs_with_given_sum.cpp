#include <iostream> 
#include <vector> 
#include <unordered_map>

using namespace std;

int countPairs_1(vector<int> &arr, int target) {
    // O(n) Complexity 
    
    int count = 0;
    unordered_map <int, int> mpp;
    for (int i = 0; i < arr.size(); i++){
        int more = target - arr[i];
        if(mpp.find(more) != mpp.end()){
            count += mpp[more];
        }
        mpp[arr[i]]++;
    }
    return count;
}

int countPairs_2(vector<int> &arr, int target){
    // Complexity O(n^2)

    int count = 0;
    for (int i = 0; i < arr.size(); i++){
        for (int j = i+1 ; j < arr.size(); j++){
            if (arr[i] + arr[j] == target){
                count ++;
            }
        }
    }
    return count;

}       
        
int main() {
    vector<int> arr = {1, 5, 7, 1};
    int target = 6; int result1 = countPairs_1(arr, target);
    int result2 = countPairs_2(arr, target);
    cout << "Count using O(n) method: " << result1 << endl;
    cout << "Count using O(n^2) method: " << result2 << endl;
    return 0;
}