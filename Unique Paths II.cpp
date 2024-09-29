#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    
    // If the starting cell is blocked, return 0
    if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) return 0;

    // Create a DP table
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1; // Starting point

    // Fill the first column
    for (int i = 1; i < m; i++) {
        dp[i][0] = grid[i][0] == 0 ? dp[i - 1][0] : 0;
    }

    // Fill the first row
    for (int j = 1; j < n; j++) {
        dp[0][j] = grid[0][j] == 0 ? dp[0][j - 1] : 0;
    }

    // Fill the DP table
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (grid[i][j] == 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[m - 1][n - 1]; // Return the value in the bottom-right corner
}

int main() {
    vector<vector<int>> grid = {{0,0,0},{0,1,0},{0,0,0}};
    cout << "Number of unique paths: " << uniquePathsWithObstacles(grid) << endl;
    return 0;
}
