#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    bool isSafe(int row, int col, int n, const vector<string>& board) {
        // Check this column upwards
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        
        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        
        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        
        return true;
    }

    void solve(int row, int n, vector<string>& board, vector<vector<string>>& ans) {
        // Base case: If all queens are placed successfully
        if (row == n) {
            ans.push_back(board);
            return;
        }
        
        // Try placing a queen in each column of the current row
        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, n, board)) {
                board[row][col] = 'Q';       // Place queen
                solve(row + 1, n, board, ans); // Recurse to next row
                board[row][col] = '.';       // Backtrack
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.')); // Initialize n x n board with '.'
        solve(0, n, board, ans);
        return ans;
    }
};