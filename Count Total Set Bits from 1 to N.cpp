#include <iostream>
using namespace std;

// Function to count total set bits from 1 to N
int countTotalSetBits(int N) {
    if (N <= 0) {
        return 0;
    }
    int count = 0;
    for (int i = 1; i <= N; i++) {
        int num = i;
        while (num > 0) {
            count += (num & 1);
            num >>= 1;
        }
    }
    return count;
}

int main() {
    int N = 10;
    cout << "Total set bits from 1 to " << N << " is: " << countTotalSetBits(N) << endl;
    return 0;
}
