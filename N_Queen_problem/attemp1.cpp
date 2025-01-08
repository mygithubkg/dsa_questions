#include<iostream>
#include<vector>

using namespace std;

bool isSafe(vector<string>& board, int col, int n, int row) {
        // Checking vertical
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        
        // Checking horizontal
        for (int j = 0; j < n; j++) {
            if (board[row][j] == 'Q') {
                return false;
            }
        }
        
        // Checking left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // Checking right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        
        return true;
    }

    void placeQ(vector<string>& board, int row, vector<vector<string>>& ans, int n) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(board, col, n, row)) {
                board[row][col] = 'Q';
                placeQ(board, row + 1, ans, n);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        placeQ(board, 0, ans, n);
    
        vector<vector<int>> locations;
    
        for (auto& solution : ans) {
            vector<int> rowPositions;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (solution[i][j] == 'Q') {
                        rowPositions.push_back(j + 1);  // Adding 1 to convert to 1-based indexing
                    }
                }
            }
            locations.push_back(rowPositions);
        }
        return locations;
    }
