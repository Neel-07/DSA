// Problem link:https://leetcode.com/problems/sqrtx/

#include <iostream>
#include <string>
using namespace std;

// Sqrt(x)
// Brute Force Solution
int mySqrt_BruteForce(int x) {
    if (x == 0 || x == 1) {
        return x;
    }
    for (long long i = 1; i <= x; i++) {
        if (i * i > x) {
            return i - 1;
        }
    }
    return -1; // Error
}

// Optimized Solution
int mySqrt_Optimized(int x) {
    if (x == 0 || x == 1) {
        return x;
    }
    int left = 1, right = x;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (mid > x / mid) {
            right = mid - 1;
        } else {
            if (mid + 1 > x / (mid + 1)) {
                return mid;
            }
            left = mid + 1;
        }
    }
    return -1; // Error
}

int main() {
    // Test the functions here
   
    return 0;
}