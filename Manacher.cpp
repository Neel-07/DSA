#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string preprocessString(const string& s) {
    string T = "^#";
    for (char c : s) {
        T += c;
        T += '#';
    }
    T += '$';
    return T;
}

string longestPalindrome(const string& s) {
    // Step 1: Preprocess the string
    string T = preprocessString(s);
    int n = T.size();
    vector<int> P(n, 0);  // Array to store the radius of palindromes
    int C = 0, R = 0;     // Center and right edge of the current right-most palindrome

    // Step 2: Populate the P array with palindrome lengths
    for (int i = 1; i < n - 1; ++i) {
        int mirror = 2 * C - i;  // Mirror of i with respect to C

        if (i < R) {
            P[i] = min(R - i, P[mirror]);
        }

        // Attempt to expand the palindrome centered at i
        while (T[i + P[i] + 1] == T[i - P[i] - 1]) {
            P[i]++;
        }

        // Update C and R if the palindrome around i expands beyond R
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    // Step 3: Find the maximum element in P
    int max_len = 0;
    int center_index = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (P[i] > max_len) {
            max_len = P[i];
            center_index = i;
        }
    }

    // Step 4: Convert the center_index of the transformed string back to the original string
    int start = (center_index - max_len) / 2;
    return s.substr(start, max_len);
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    string result = longestPalindrome(s);
    cout << "Longest palindromic substring: " << result << endl;

    return 0;
}
