// problem link:https://leetcode.com/problems/reverse-integer/

#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    // Brute Force Solution
    int reverse(int x) {
         int ans=0, rem;
        
        while(x!=0){
            rem=x%10;
            x=x/10;
            if(ans>INT_MAX/10 || ans<INT_MIN/10){
                return 0;
            }
            ans=ans*10+rem;
        }
        return ans;
    }
    
    // Optimized Solution
    int reverseOptimized(int x) {
        int reversed = 0;
        
        // Reversing the integer using modulo and division
        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            
            // Check for overflow before updating the reversed integer
            if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && digit > 7)) {
                return 0; // Return 0 for overflow
            }
            if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && digit < -8)) {
                return 0; // Return 0 for overflow
            }
            
            reversed = reversed * 10 + digit;
        }
        
        return reversed;
    }
};

int main() {
    Solution sol;
    int num = -123; // Test input
    
    // Test the brute force solution
    int resultBruteForce = sol.reverse(num);
    cout << "Result using the brute force solution: " << resultBruteForce << endl;
    
    // Test the optimized solution
    int resultOptimized = sol.reverseOptimized(num);
    cout << "Result using the optimized solution: " << resultOptimized << endl;
    
    return 0;
}
