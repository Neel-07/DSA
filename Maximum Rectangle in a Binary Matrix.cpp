#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// Helper function to calculate the largest rectangle in histogram
int maxHistogramArea(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;
    int n = heights.size();

    for (int i = 0; i <= n; i++) {
        int h = (i == n) ? 0 : heights[i];
        while (!s.empty() && h < heights[s.top()]) {
            int height = heights[s.top()];
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        s.push(i);
    }

    return maxArea;
}

// Main function to find the maximal rectangle area in binary matrix
int maximalRectangle(vector<vector<int>>& matrix) {
    if (matrix.empty()) return 0;

    int maxArea = 0;
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> heights(n, 0);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // Update heights array
            heights[j] = matrix[i][j] == 1 ? heights[j] + 1 : 0;
        }
        // Calculate maximum area for the current row histogram
        maxArea = max(maxArea, maxHistogramArea(heights));
    }

    return maxArea;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 0, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}
    };

    int maxArea = maximalRectangle(matrix);
    cout << "Maximum rectangle area of 1s: " << maxArea << endl;

    return 0;
}
