#include <iostream>
using namespace std;

// Function to find the position of the first set bit
int findFirstSetBit(int N) {
    // If N is 0, return 0 since there is no set bit
    if (N == 0) {
        return 0;
    }
    // Initialize position as 1
    int position = 1;
    // Iterate until we find the first set bit
    for (int i = 0; i < 32; i++) {
        if ((N & (1 << i)) > 0) {
            position = i + 1;
            break;
        }
    }
    return position;
}

int main() {
    int N = 18;
    cout << "Position of the first set bit in " << N << " is: " << findFirstSetBit(N) << endl;
    return 0;
}
