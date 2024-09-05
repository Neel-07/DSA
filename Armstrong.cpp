// Brute Force Approach:
// This approach involves checking every number in the given range to see if it's an Armstrong number by calculating the sum of each digit raised to the power of the number of digits.

#include <iostream>
#include <cmath>
using namespace std;

// Function to check if a number is an Armstrong number
bool isArmstrong(int num) {
    int original = num, sum = 0, digits = 0;
    
    // Find number of digits
    while (original != 0) {
        digits++;
        original /= 10;
    }

    original = num;
    
    // Calculate the sum of each digit raised to the power of the number of digits
    while (original != 0) {
        int digit = original % 10;
        sum += pow(digit, digits);
        original /= 10;
    }

    return sum == num;
}

// Brute force method to generate Armstrong numbers in a given range
void generateArmstrongNumbersBruteForce(int start, int end) {
    for (int i = start; i <= end; i++) {
        if (isArmstrong(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int start = 1, end = 10000;
    
    // Generate Armstrong numbers between 1 and 10000 using brute force
    cout << "Armstrong numbers (Brute Force): ";
    generateArmstrongNumbersBruteForce(start, end);

    return 0;
    
}


// Time and Space Complexity (Brute Force):
// Time Complexity: 
// 𝑂
// (
// 𝑛
// ⋅
// 𝑑
// )
// O(n⋅d), where 
// 𝑛
// n is the number of integers in the range and 
// 𝑑
// d is the number of digits in the integer (which is 
// 𝑂
// (
// log
// ⁡
// 10
// 𝑛
// )
// O(log 
// 10
// ​
//  n)). For each number, calculating the sum of powers takes 
// 𝑂
// (
// 𝑑
// )
// O(d) time.
// Space Complexity: 
// 𝑂
// (
// 1
// )
// O(1), no extra space is required apart from the number being checked.
// Optimized Approach:
// The optimized approach improves by precomputing the powers of digits (0 to 9) up to the maximum number of digits in the range. This reduces repetitive computations of powers for each number.




#include <iostream>
#include <cmath>
using namespace std;

// Precompute powers of digits to avoid recomputation
int digitPowers[10][10];

// Function to precompute powers for digits 0-9 up to maxDigits
void precomputePowers(int maxDigits) {
    for (int digit = 0; digit < 10; digit++) {
        for (int power = 1; power <= maxDigits; power++) {
            digitPowers[digit][power] = pow(digit, power);
        }
    }
}

// Optimized function to check if a number is an Armstrong number
bool isArmstrongOptimized(int num) {
    int original = num, sum = 0, digits = 0;

    // Find number of digits
    while (original != 0) {
        digits++;
        original /= 10;
    }

    original = num;
    
    // Calculate the sum of each digit raised to the power of the number of digits
    while (original != 0) {
        int digit = original % 10;
        sum += digitPowers[digit][digits];  // Use precomputed powers
        original /= 10;
    }

    return sum == num;
}

// Optimized method to generate Armstrong numbers in a given range
void generateArmstrongNumbersOptimized(int start, int end) {
    for (int i = start; i <= end; i++) {
        if (isArmstrongOptimized(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int start = 1, end = 10000;
    
    // Precompute powers for digits up to 5 (since 9999 has 4 digits, we compute powers up to 5)
    precomputePowers(5);
    
    // Generate Armstrong numbers between 1 and 10000 using the optimized approach
    cout << "Armstrong numbers (Optimized): ";
    generateArmstrongNumbersOptimized(start, end);

    return 0;
}


// Time and Space Complexity (Optimized):
// Time Complexity: 
// 𝑂
// (
// 𝑛
// )
// O(n), where 
// 𝑛
// n is the number of integers in the range. The sum of powers for each number takes 
// 𝑂
// (
// 𝑑
// )
// O(d) in the worst case, but using precomputed powers reduces constant overhead. The complexity is dominated by the loop over 
// 𝑛
// n.
// Space Complexity: 
// 𝑂
// (
// 1
// )
// O(1) for the space used by the function and 
// 𝑂
// (
// 10
// ×
// 𝑚
// 𝑎
// 𝑥
// 𝐷
// 𝑖
// 𝑔
// 𝑖
// 𝑡
// 𝑠
// )
// O(10×maxDigits) for the precomputed powers table, which is constant for reasonable ranges of 
// 𝑛
// n.