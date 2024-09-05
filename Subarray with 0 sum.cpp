// C++ program to find if
// there is a zero sum subarray
#include <iostream>
using namespace std;

bool subArrayExists(int arr[], int n)
{
	for (int i = 0; i < n; i++) {
	
		// starting point of the sub arrray and
		// sum is initialized with first element of subarray
		// a[i]
		int sum = arr[i];
		if (sum == 0)
			return true;
		for (int j = i + 1; j < n; j++) {
		
			// we are finding the sum till jth index
			// starting from ith index
			sum += arr[j];
			if (sum == 0)
				return true;
		}
	}
	return false;
}

// Driver's code
int main()
{
	int arr[] = { -3, 2, 3, 1, 6 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	if (subArrayExists(arr, N))
		cout << "Found a subarray with 0 sum";
	else
		cout << "No Such Sub Array Exists!";
	return 0;
}

// This code is contributed by Tapesh(tapeshdua420)
