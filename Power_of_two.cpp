// Problem link:https://leetcode.com/problems/sqrtx/

#include <iostream>
#include <string>
using namespace std;

// Power of Two
// Brute Force Solution
bool isPowerOfTwo_BruteForce(int n) {
    if (n <= 0) {
        return false;
    }
    while (n % 2 == 0) {
        n /= 2;
    }
    return n == 1;
}

// Optimized Solution
bool isPowerOfTwo_Optimized(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    // Test the functions here
   
    return 0;
}