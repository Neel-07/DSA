#include <bits/stdc++.h>

using namespace std;

vector<int> duplicates(long long arr[], int n) {
    // Step 1: Create an empty unordered map to store element frequencies
    unordered_map<long long, int> freqMap;
    vector<int> result;

    // Step 2: Iterate through the array and count element frequencies
    for (int i = 0; i < n; i++) {
        freqMap[arr[i]]++;
    }

    // Step 3: Iterate through the hashmap to find duplicates
    for (auto& entry : freqMap) {
        if (entry.second > 1) {
            result.push_back(entry.first);
        }
    }

    // Step 4: If no duplicates found, add -1 to the result
    if (result.empty()) {
        result.push_back(-1);
    }
    //step 5: sort the result
    sort(result.begin(),result.end());
    // Step 6: Return the result vector containing duplicate elements or -1
    return result;
}

int main() {
    long long a[] = {1, 6, 5, 2, 3, 3, 2};
    int n = sizeof(a) / sizeof(a[0]);
    
    vector<int> duplicates_found = duplicates(a, n);
    
    cout << "Duplicate elements: ";
    for (int element : duplicates_found) {
        cout << element << " ";
    }
    cout << endl;
    
    return 0;
}
