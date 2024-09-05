// C++ code for the above approach

#include <bits/stdc++.h>
using namespace std;

// function to check if the string can be
// rearranged to a palindromic string or not
bool ispalindromic(string s)
{

	int n = s.size();
	// hashmap to count the frequency of
	// every character in given substring
	unordered_map<char, int> hashmap;

	for (auto ch : s) {
		hashmap[ch]++;
	}

	int count = 0;

	// Count of characters having odd frequency
	for (auto i : hashmap) {
		if (i.second % 2 == 1)
			count++;
	}

	// if count is greater than 1
	if (count > 1) {
		return false;
	}

	return true;
}
// Function to get the length of longest
// substring whose characters can be
// arranged to form a palindromic string
int longestSubstring(string S, int n)
{
	int ans = 0;

	for (int i = 0; i < S.size(); i++) {
		string curstr = "";
		for (int j = i; j < S.size(); j++) {
		
			// Storing the substring
			curstr += S[j];
		
			// Checking if it is possible to
			// make it a palindrome
			if (ispalindromic(curstr)
				== true) 
			{
			
				// Storing the maximum answer
				ans = max(ans, j - i + 1);
			}
		}
	}

	return ans;
}

// Driver code
int main()
{

	// Given String
	string s = "adbabd";

	// Length of given string
	int n = s.size();

	// Function call
	cout << (longestSubstring(s, n));
}

// This code is contributed by Arpit Jain
