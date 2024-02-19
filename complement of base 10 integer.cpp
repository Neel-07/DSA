// Problem link :https://leetcode.com/problems/complement-of-base-10-integer/


class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) {
            return 1; // Bitwise complement of 0 is 1
        }

        int rem, ans = 0, mul = 1; // Initialize variables for remainder, answer, and multiplier

        // Brute force approach to calculate bitwise complement
        while (n) {
            rem = n % 2; // Get the remainder of n when divided by 2
            rem = rem ^ 1; // Perform XOR operation to get the complement of the remainder
            ans = ans + rem * mul; // Calculate the complement and add to the answer
            n = n / 2; // Right shift n by 1 bit (equivalent to dividing by 2)
            mul = mul * 2; // Multiply the multiplier by 2 for the next iteration
        }
        
        return ans; // Return the calculated bitwise complement
    }

    int bitwiseCom(int n) {
        int mask = 1; // Initialize a mask with the least significant bit set
        while (mask < n) {
            mask = (mask << 1) + 1; // Left shift the mask by 1 and set the new bit as 1
        }
        
        return n ^ mask; // Perform bitwise XOR with the mask to get the complement
    }
};
