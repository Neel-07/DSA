#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int matrix[5][5];
    int x, y;

    // Input the matrix and find the position of '1'
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1) {
                x = i + 1; // Convert to 1-based index
                y = j + 1; // Convert to 1-based index
            }
        }
    }

    // Calculate the Manhattan distance to the center (3, 3)
    int moves = abs(x - 3) + abs(y - 3);

    // Output the result
    cout << moves << endl;

    return 0;
}
