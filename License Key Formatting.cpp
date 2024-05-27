// C++ code for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to compute the answer
string ReFormatString(string S, int K)
{
	// Create a temporary string to store
	// the alphanumeric characters only
	string temp;
	int n = S.length();
	for (int i = 0; i < n; i++) {
		if (S[i] != '-') {

			temp.push_back(toupper(S[i]));
		}
	}
	int len = temp.length();

	// String ans is created to store
	// the final string.
	string ans;
	int val = K;

	// Iterate over the string from right
	// to left and start pushing
	// characters at an interval of K
	for (int i = len - 1; i >= 0; i--) {
		if (val == 0) {
			val = K;
			ans.push_back('-');
		}
		ans.push_back(temp[i]);
		val--;
	}

	// Reverse the final string and
	// return it.
	reverse(ans.begin(), ans.end());
	return ans;
}

// Driver code
int main()
{
	string s = "5F3Z-2e-9-w";
	int K = 4;

	// Function Call
	cout << ReFormatString(s, K);
	return 0;
}
