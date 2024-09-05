#include <iostream>
#include <set>
using namespace std;

// Function to find all distinct palindrome 
// substrings in a given string
int GFG(string str, set<string> &result) {
	int n = str.length();
	bool dp[n][n];
	for (int gap = 0; gap < n; gap++) {
		for (int i = 0, j = gap; j < n; i++, j++) {
			if (gap == 0)
				dp[i][j] = true; 
		// Single characters are palindromes
			else if (gap == 1)
				dp[i][j] = (str[i] == str[j]); 
		// Two characters are palindromes if they are the same
			else
				dp[i][j] = (str[i] == str[j] && dp[i + 1][j - 1]); 
		// Check if the substring is a palindrome
			if (dp[i][j])
				result.insert(str.substr(i, j - i + 1));
		}
	}
	return result.size(); 
// Return the count of distinct palindromic substrings
}
int main() {
	string str = "abaaa";
	set<string> result;
	// Call the function to find palindromic substrings
	GFG(str, result);
	cout << "Number of distinct palindromic substrings are: " << result.size() << endl;
	// Print the distinct palindromic substrings
	for (const string &s : result)
		cout << s << endl;
	return 0;
}
