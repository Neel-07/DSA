#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSumNonAdjacent(const vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;
    if (n == 1) return max(0, arr[0]);

    // Define DP arrays
    vector<int> dp(n, 0);  // dp[i] stores the maximum sum including arr[i]

    // Initialize for the first element
    dp[0] = max(0, arr[0]);
    dp[1] = max(dp[0], max(0, arr[1]));
    dp[1] = max(dp[1], arr[0] + arr[1]); // Handle case where we pick two adjacent once

    // Fill the DP table
    for (int i = 2; i < n; i++) {
        // Case 1: Exclude current element
        dp[i] = dp[i - 1];
        // Case 2: Include current element, exclude the previous one
        dp[i] = max(dp[i], dp[i - 2] + arr[i]);
        // Case 3: Take two adjacent elements once
        if (i >= 2)
            dp[i] = max(dp[i], dp[i - 3] + arr[i - 1] + arr[i]);
    }

    return dp[n - 1];
}

int main() {
    vector<int> arr = {3, 2, 5, 10, 7};
    cout << "Maximum sum of non-adjacent elements: " << maxSumNonAdjacent(arr) << endl;
    return 0;
}
