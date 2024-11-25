#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility> // For std::pair

using namespace std;

int countUniqueQuadruples(vector<int>& arr) {
    unordered_map<int, vector<pair<int, int>>> sumMap; // Map to store sum and pairs of indices
    int count = 0;

    // Traverse all pairs in the array
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = i + 1; j < arr.size(); ++j) {
            int currentSum = arr[i] + arr[j];

            // If the sum already exists in the map, check for unique quadruples
            if (sumMap.find(currentSum) != sumMap.end()) {
                for (const auto& p : sumMap[currentSum]) {
                    // Ensure all indices are unique
                    if (p.first != i && p.first != j && p.second != i && p.second != j) {
                        count++;
                    }
                }
            }

            // Add the current pair to the map
            sumMap[currentSum].emplace_back(i, j);
        }
    }

    return count;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    cout << "Count of unique quadruples: " << countUniqueQuadruples(arr) << endl;
    return 0;
}
