#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // Helper function to expand around the center and find the longest palindrome
    string expandAroundCenter(string s, int left, int right) {
        // Expand while the characters on both sides are equal and within bounds
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Return the palindrome substring
        return s.substr(left + 1, right - left - 1);
    }

    // Main function to find the longest palindromic substring
    string longestPalindrome(string s) {
        if (s.empty()) return "";  // Edge case: Empty string

        string longest = "";  // To store the longest palindrome found
        
        // Loop through each character in the string to consider it as the center
        for (int i = 0; i < s.length(); i++) {
            // Check for odd-length palindromes (centered at a single character)
            string oddPalindrome = expandAroundCenter(s, i, i);
            // Check for even-length palindromes (centered between two characters)
            string evenPalindrome = expandAroundCenter(s, i, i + 1);
            
            // Update the longest palindrome found so far
            if (oddPalindrome.length() > longest.length()) {
                longest = oddPalindrome;
            }
            if (evenPalindrome.length() > longest.length()) {
                longest = evenPalindrome;
            }
        }
        return longest;  // Return the longest palindrome
    }
};

// Example usage:
int main() {
    Solution sol;
    string s = "babad";
    cout << "Longest Palindromic Substring: " << sol.longestPalindrome(s) << endl;
    return 0;
}
