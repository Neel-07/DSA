#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    
    // DP table where dp[i][j] represents the minimum operations needed to convert
    // the first i characters of word1 to the first j characters of word2.
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    // Fill the base cases.
    for (int i = 0; i <= m; ++i) dp[i][0] = i; // Deleting all characters of word1
    for (int j = 0; j <= n; ++j) dp[0][j] = j; // Inserting all characters of word2
    
    // Fill the rest of the dp table.
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // No change needed
            } else {
                dp[i][j] = 1 + min({dp[i - 1][j],    // Delete
                                    dp[i][j - 1],    // Insert
                                    dp[i - 1][j - 1] // Replace
                                   });
            }
        }
    }
    
    return dp[m][n];
}

int main() {
    string word1 = "horse";
    string word2 = "ros";
    cout << "Minimum operations to convert " << word1 << " to " << word2 << ": " << minDistance(word1, word2) << endl;
    return 0;
}
