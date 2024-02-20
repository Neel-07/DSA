// problem link: https://leetcode.com/problems/ugly-number/


#include<vector>
#include <algorithm>


class Solution 
{
    public:
    // Brute force approach to find ugly numbers
bool isUgly(int num) {
    if (num <= 0) return false;
    while (num % 2 == 0) {
        num /= 2;
    }
    while (num % 3 == 0) {
        num /= 3;
    }
    while (num % 5 == 0) {
        num /= 5;
    }
    return num == 1;
}


// Optimized approach to find ugly numbers
int getNthUglyNumber(int n) {
    std::vector<int> uglyNums(n, 1);
    int i2 = 0, i3 = 0, i5 = 0;
    int nextMultipleOf2 = 2, nextMultipleOf3 = 3, nextMultipleOf5 = 5;
    for (int i = 1; i < n; i++) {
        int nextUglyNum = std::min(nextMultipleOf2, std::min(nextMultipleOf3, nextMultipleOf5));
        uglyNums[i] = nextUglyNum;
        if (nextUglyNum == nextMultipleOf2) {
            i2++;
            nextMultipleOf2 = uglyNums[i2] * 2;
        }
        if (nextUglyNum == nextMultipleOf3) {
            i3++;
            nextMultipleOf3 = uglyNums[i3] * 3;
        }
        if (nextUglyNum == nextMultipleOf5) {
            i5++;
            nextMultipleOf5 = uglyNums[i5] * 5;
        }
    }
    return uglyNums[n - 1];
}


};