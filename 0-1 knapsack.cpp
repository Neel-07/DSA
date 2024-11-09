#include <iostream>
#include <vector>

class KnapsackSolver {
public:
    int knapsack(vector<int>& values, vector<int>& weights, int capacity) {
        int n = values.size();
        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
        
        for(int i = 1; i <= n; i++) {
            for(int w = 0; w <= capacity; w++) {
                if(weights[i-1] <= w) {
                    dp[i][w] = max(values[i-1] + dp[i-1][w-weights[i-1]], 
                                 dp[i-1][w]);
                } else {
                    dp[i][w] = dp[i-1][w];
                }
            }
        }
        return dp[n][capacity];
    }
    
    // Space optimized version
    int knapsackOptimized(vector<int>& values, vector<int>& weights, int capacity) {
        vector<int> dp(capacity + 1, 0);
        
        for(int i = 0; i < values.size(); i++) {
            for(int w = capacity; w >= weights[i]; w--) {
                dp[w] = max(dp[w], values[i] + dp[w - weights[i]]);
            }
        }
        return dp[capacity];
    }
};