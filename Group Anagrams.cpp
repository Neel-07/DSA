#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Main function to group anagrams
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;  // HashMap to store sorted words as keys
        
        // Loop through each word in the list
        for (string word : strs) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());  // Sort the word alphabetically
            anagramMap[sortedWord].push_back(word);  // Add the original word to the sorted key's group
        }
        
        // Prepare the result vector from the hash map
        vector<vector<string>> result;
        for (auto& group : anagramMap) {
            result.push_back(group.second);  // Add each group of anagrams to the result
        }
        
        return result;  // Return the grouped anagrams
    }
};

// Example usage:
int main() {
    Solution sol;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = sol.groupAnagrams(strs);
    
    // Output the result
    for (const auto& group : result) {
        cout << "[ ";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}
