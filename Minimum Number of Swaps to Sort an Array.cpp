#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minSwaps(vector<int>& arr) {
    int n = arr.size();
    vector<pair<int, int>> arrPos(n);
    
    // Store the original elements along with their positions
    for (int i = 0; i < n; i++) {
        arrPos[i] = {arr[i], i};
    }
    
    // Sort the array by element value
    sort(arrPos.begin(), arrPos.end());

    // To keep track of visited elements
    vector<bool> visited(n, false);
    int swaps = 0;

    // Traverse the array elements and calculate cycles
    for (int i = 0; i < n; i++) {
        if (visited[i] || arrPos[i].second == i)
            continue;
        
        // Find the cycle length
        int cycle_size = 0;
        int j = i;

        while (!visited[j]) {
            visited[j] = true;
            j = arrPos[j].second;
            cycle_size++;
        }

        // If there is a cycle of size k, we need k-1 swaps
        if (cycle_size > 1)
            swaps += (cycle_size - 1);
    }

    return swaps;
}

int main() {
    vector<int> arr = {4, 3, 2, 1};
    cout << "Minimum number of swaps: " << minSwaps(arr) << endl;
    return 0;
}
