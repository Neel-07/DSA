#include <iostream>
#include <vector>
using namespace std;

// Function to solve the 0/1 Knapsack problem
int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    // DP table to store maximum value achievable with given weights
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build table dp[][] in a bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    // The last cell of dp table contains the maximum value for the given weight
    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> W;

    vector<int> weights(n), values(n);
    
    cout << "Enter weights of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    
    cout << "Enter values of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    int max_value = knapsack(W, weights, values, n);
    cout << "Maximum value that can be obtained: " << max_value << endl;

    return 0;
}
