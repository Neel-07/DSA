#include <iostream>
#include <vector>
using namespace std;

int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1; // Base case: There's one way to make amount 0.
    
    for (int coin : coins) {
        for (int i = coin; i <= amount; ++i) {
            dp[i] += dp[i - coin];
        }
    }
    
    return dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    cout << "Number of ways to make change: " << change(amount, coins) << endl;
    return 0;
}
