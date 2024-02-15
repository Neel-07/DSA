// Problem link:https://leetcode.com/problems/palindrome-number/

#include <iostream>
#include <string>
using namespace std;


// Palindrome Number
// Brute Force Solution
bool isPalindrome_BruteForce(int x) {
    string s = to_string(x);
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

// Optimized Solution
bool isPalindrome_Optimized(int x) {
    if (x < 0) {
        return false;
    }
    int original = x;
    long long reversed = 0;
    while (x != 0) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    return original == reversed;
}

int main() {
    // Test the functions here
   
    return 0;
}