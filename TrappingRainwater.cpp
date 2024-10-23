#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    // Create arrays to store the maximum height to the left and right of each bar
    vector<int> leftMax(n);
    vector<int> rightMax(n);

    // Fill leftMax array
    leftMax[0] = height[0];
    for (int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    // Fill rightMax array
    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    // Calculate the total water trapped
    int waterTrapped = 0;
    for (int i = 0; i < n; i++) {
        // The water trapped at index i is the minimum of the maximum heights to its left and right, minus its own height
        waterTrapped += min(leftMax[i], rightMax[i]) - height[i];
    }

    return waterTrapped;
}

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; // Example input
    cout << "Water trapped: " << trap(height) << " units" << endl;
    return 0;
}

