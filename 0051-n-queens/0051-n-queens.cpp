#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    bool isvalid(int n, const vector<string>& board, int i, int j) {

        // 1. Check vertically upwards
        for (int row = i - 1; row >= 0; row--) {
            if (board[row][j] == 'Q') {
                return false;
            }
        }
       
        // 2. Check upper-right diagonal
        for (int row = i - 1, step = 1; row >= 0 && j + step < n; row--, step++) {
            if (board[row][j + step] == 'Q') {
                return false;
            }
        }

        // 3. Check upper-left diagonal
        for (int row = i - 1, step = 1; row >= 0 && j - step >= 0; row--, step++) {
            if (board[row][j - step] == 'Q') {
                return false;
            }
        }

        return true; // No conflicts found, position is safe
    }


    void f(int n, vector<string>& board, vector<vector<string>>& allBoards, int i) {
        // Base case: If we have placed queens in all rows (0 to n-1)
        if (i == n) {
            allBoards.push_back(board);
            return;
        }

        // Recursive case: Try placing a queen in each column of row 'i'
        for (int j = 0; j < n; j++) {
            if (isvalid(n, board, i, j)) {
                board[i][j] = 'Q';          // Place queen
                f(n, board, allBoards, i + 1); // Recurse for the next row
                board[i][j] = '.';          // Backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        for (int i = 0; i < n; i++) {
            string row(n, '.');
            board.push_back(row);
        }

        vector<vector<string>> allBoards;

        f(n, board, allBoards, 0);

        return allBoards;
    }
};