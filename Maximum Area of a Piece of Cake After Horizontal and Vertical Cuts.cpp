#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        const int MOD = 1e9 + 7;

        // Sort the cuts
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        // Calculate maximum height difference
        int maxHorizontalGap = max(horizontalCuts[0], h - horizontalCuts.back());
        for (int i = 1; i < horizontalCuts.size(); ++i) {
            maxHorizontalGap = max(maxHorizontalGap, horizontalCuts[i] - horizontalCuts[i - 1]);
        }

        // Calculate maximum width difference
        int maxVerticalGap = max(verticalCuts[0], w - verticalCuts.back());
        for (int i = 1; i < verticalCuts.size(); ++i) {
            maxVerticalGap = max(maxVerticalGap, verticalCuts[i] - verticalCuts[i - 1]);
        }

        // Calculate maximum area modulo 10^9 + 7
        return (1LL * maxHorizontalGap * maxVerticalGap) % MOD;
    }
};

int main() {
    Solution solution;
    int h = 5, w = 4;
    vector<int> horizontalCuts = {1, 2, 4};
    vector<int> verticalCuts = {1, 3};
    cout << solution.maxArea(h, w, horizontalCuts, verticalCuts) << endl; // Output: 4
    return 0;
}
