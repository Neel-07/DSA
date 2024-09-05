// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;

// Function to return the union of two arrays
vector<int> Unionarray(int arr1[], int arr2[], int n, int m)
{
	set<int> s;
	// Remove the duplicates from arr1[]
	for (int i = 0; i < n; i++) {
		s.insert(arr1[i]);
	}

	// Remove duplicates from arr2[]
	for (int i = 0; i < m; i++) {
		s.insert(arr2[i]);
	}

	// Loading set to vector
	vector<int> vec(s.begin(), s.end());

	return vec;
}

// Driver code
int main()
{
	int arr1[] = { 1, 2, 2, 2, 3 };
	int arr2[] = { 2, 3, 3, 4, 5, 5 };
	int n = sizeof(arr1) / sizeof(arr1[0]);
	int m = sizeof(arr2) / sizeof(arr2[0]);

	// Function call
	vector<int> uni = Unionarray(arr1, arr2, n, m);
	for (int i : uni) {
		cout << i << " ";
	}

	return 0;
}
