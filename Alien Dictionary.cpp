#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

string alienOrder(vector<string>& words) {
    // Step 1: Build the graph
    unordered_map<char, unordered_set<char>> graph;
    unordered_map<char, int> inDegree;

    // Initialize in-degree for each character
    for (const string& word : words) {
        for (char c : word) {
            inDegree[c] = 0;  // Initialize in-degree to 0
        }
    }

    // Create edges based on the character order in the alien dictionary
    for (int i = 0; i < words.size() - 1; ++i) {
        const string& word1 = words[i];
        const string& word2 = words[i + 1];
        int minLength = min(word1.size(), word2.size());
        
        for (int j = 0; j < minLength; ++j) {
            if (word1[j] != word2[j]) {
                if (graph[word1[j]].insert(word2[j]).second) {
                    inDegree[word2[j]]++;  // Increment in-degree of the next character
                }
                break;  // Only the first different character is important
            }
        }
    }

    // Step 2: Perform topological sort using Kahn's algorithm
    queue<char> q;
    for (const auto& entry : inDegree) {
        if (entry.second == 0) {
            q.push(entry.first);  // Push all characters with in-degree 0
        }
    }

    string result;
    while (!q.empty()) {
        char current = q.front();
        q.pop();
        result += current;  // Add current character to the result

        // Reduce in-degree of adjacent characters
        for (char neighbor : graph[current]) {
            if (--inDegree[neighbor] == 0) {
                q.push(neighbor);  // Push to queue if in-degree becomes 0
            }
        }
    }

    // If result size is less than the number of unique characters, there is a cycle
    if (result.size() < inDegree.size()) {
        return "";  // Cycle detected, invalid order
    }

    return result;
}

int main() {
    vector<string> words = {"z", "x", "z"};
    string order = alienOrder(words);
    
    if (order.empty()) {
        cout << "There is no valid order." << endl;
    } else {
        cout << "The order of characters is: " << order << endl;
    }

    return 0;
}
