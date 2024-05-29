#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Define a struct to represent BigInteger
struct BigInteger {
	string str;

	// Constructor to initialize
	// BigInteger with a string
	BigInteger(string s) { str = s; }

	// Overload + operator to add
	// two BigInteger objects
	BigInteger operator+(const BigInteger& b)
	{
		string a = str;
		string c = b.str;
		int alen = a.length(), clen = c.length();
		int n = max(alen, clen);
		if (alen > clen)
			c.insert(0, alen - clen, '0');
		else if (alen < clen)
			a.insert(0, clen - alen, '0');
		string res(n + 1, '0');
		int carry = 0;
		for (int i = n - 1; i >= 0; i--) {
			int digit = (a[i] - '0') + (c[i] - '0') + carry;
			carry = digit / 10;
			res[i + 1] = digit % 10 + '0';
		}
		if (carry == 1) {
			res[0] = '1';
			return BigInteger(res);
		}
		else {
			return BigInteger(res.substr(1));
		}
	}

	// Overload << operator to output
	// BigInteger object
	friend ostream& operator<<(ostream& out,
							const BigInteger& b)
	{
		out << b.str;
		return out;
	}
};

// Driver Code
int main()
{
	string str = "7777555511111111";
	string str1 = "3332222221111";

	// Create BigInteger objects
	// and add them
	BigInteger a(str);
	BigInteger b(str1);
	BigInteger sum = a + b;

	// Output the result
	cout << sum << endl;
	return 0;
}
