#include <iostream>
#include <vector>
using namespace std;

bool canPartition(vector<int>& nums) {
    int totalSum = 0;
    for (int num : nums) totalSum += num;
    
    // If the total sum is odd, we cannot partition it into two equal subsets.
    if (totalSum % 2 != 0) return false;
    
    int target = totalSum / 2;
    int n = nums.size();
    
    // DP array to store if a certain sum is achievable.
    vector<bool> dp(target + 1, false);
    dp[0] = true; // We can always achieve the sum of 0.
    
    // For each number in the array, update the dp array.
    for (int num : nums) {
        for (int i = target; i >= num; --i) {
            dp[i] = dp[i] || dp[i - num];
        }
    }
    
    return dp[target];
}

int main() {
    vector<int> nums = {1, 5, 11, 5};
    if (canPartition(nums)) {
        cout << "Can partition the array into two subsets with equal sum." << endl;
    } else {
        cout << "Cannot partition the array into two subsets with equal sum." << endl;
    }
    return 0;
}
