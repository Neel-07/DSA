// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;

// Function to return shortest distance
int shortestDistance(vector<string>& s,
					string word1, string word2)
{
	int d1 = -1, d2 = -1;
	int ans = INT_MAX;

	// Traverse the string
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == word1)
			d1 = i;
		if (s[i] == word2)
			d2 = i;
		if (d1 != -1 && d2 != -1)
			ans = min(ans, abs(d1 - d2));
	}

	// Return the answer
	return ans;
}

// Driver Code
int main()
{
	vector<string> S
		= { "the", "quick", "brown", "fox", "quick" };

	string word1 = "the", word2 = "fox";

	// Function Call
	cout << shortestDistance(S, word1, word2);

	return 0;
}
