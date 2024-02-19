// problem link : https://www.geeksforgeeks.org/problems/squares-in-nn-chessboard1801/


class Solution {
public:
    // Brute force solution
    int totalSquaresBruteForce(int N) {
        int total = 0;
        for (int i = 1; i <= N; i++) {
            total += i * i;  // Adding the squares of all sizes up to N
        }
        return total;
    }

    // Optimized solution
    int totalSquaresOptimized(int N) {
        return N * (N + 1) * (2 * N + 1) / 6;  // Calculating the total squares using the formula
    }

    // Function to call either the brute force or the optimized solution based on a boolean flag
    int totalSquares(int N, bool useOptimized) {
        if (useOptimized) {
            return totalSquaresOptimized(N);  // Call the optimized solution
        } else {
            return totalSquaresBruteForce(N);  // Call the brute force solution
        }
    }
};
