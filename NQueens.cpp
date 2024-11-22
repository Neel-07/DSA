#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        vector<string> board(n, string(n, '.')); // Initialize an empty board
        unordered_set<int> columns, diagonals, antiDiagonals;
        backtrack(0, n, board, columns, diagonals, antiDiagonals, results);
        return results;
    }

private:
    void backtrack(int row, int n, vector<string>& board,
                   unordered_set<int>& columns,
                   unordered_set<int>& diagonals,
                   unordered_set<int>& antiDiagonals,
                   vector<vector<string>>& results) {
        if (row == n) {
            results.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            // Check if the position is safe
            if (columns.count(col) || diagonals.count(row - col) || antiDiagonals.count(row + col))
                continue;

            // Place the queen
            board[row][col] = 'Q';
            columns.insert(col);
            diagonals.insert(row - col);
            antiDiagonals.insert(row + col);

            // Recurse to the next row
            backtrack(row + 1, n, board, columns, diagonals, antiDiagonals, results);

            // Backtrack: Remove the queen
            board[row][col] = '.';
            columns.erase(col);
            diagonals.erase(row - col);
            antiDiagonals.erase(row + col);
        }
    }
};

int main() {
    int n = 4;
    Solution solution;
    vector<vector<string>> results = solution.solveNQueens(n);

    cout << "Solutions for " << n << "-Queens:\n";
    for (const auto& solution : results) {
        for (const string& row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
