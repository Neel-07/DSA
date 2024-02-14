// Problem link : https://leetcode.com/problems/add-digits/

#include <iostream>
using namespace std;

/*
Naive Iterative Approach:
This implementation uses a while loop to continuously sum the digits of the given number 
until the result is a single digit.
*/
int addDigits(int num) {
    while (num >= 10) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        num = sum;
    }
    return num;
}

/*
Provided Iterative Approach:
This implementation iteratively extracts the individual digits from the input number 
and accumulates their sum until a single digit is obtained.
*/
class Solution {
public:
    int addDigits(int num) {
        
        while(num>9){
            int ans=0, rem;
            while(num!=0){
                rem = num % 10;
                num = num / 10;
                ans=ans+rem;
            }
            num = ans;
        }
      return num;   
    }
};

/*
Optimized Mathematical Approach:
This optimized implementation exploits the mathematical properties of digital roots to 
directly compute the result without using loops.
*/
class Solution {
public:
    int addDigits(int num) {
        if(num == 0) return 0;
        else if(num % 9 == 0) return 9;
        else return num % 9;
    }
};

int main() {
    // Testing the addDigits function
    int testNumber = 9876;
    cout << "Naive Iterative Approach: " << addDigits(testNumber) << endl;
    
    Solution sol;
    cout << "Provided Iterative Approach: " << sol.addDigits(testNumber) << endl;

    cout << "Optimized Mathematical Approach: " << sol.addDigits(testNumber) << endl;

    return 0;
}
