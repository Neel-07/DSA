#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// Helper function to perform BFS and store paths
void bfsLayers(const string& beginWord, const string& endWord, unordered_set<string>& wordSet, unordered_map<string, vector<string>>& parent) {
    unordered_set<string> beginSet{beginWord}, endSet{endWord};
    bool found = false, backward = false;

    while (!beginSet.empty() && !found) {
        if (beginSet.size() > endSet.size()) {
            swap(beginSet, endSet);
            backward = !backward;
        }

        unordered_set<string> tempSet;
        for (const string& word : beginSet) {
            wordSet.erase(word); // Erase to prevent revisiting
        }

        for (const string& word : beginSet) {
            string currentWord = word;
            for (int i = 0; i < currentWord.size(); ++i) {
                char originalChar = currentWord[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    currentWord[i] = c;
                    if (endSet.count(currentWord)) {
                        found = true;
                        backward ? parent[currentWord].push_back(word) : parent[word].push_back(currentWord);
                    } else if (!found && wordSet.count(currentWord)) {
                        tempSet.insert(currentWord);
                        backward ? parent[currentWord].push_back(word) : parent[word].push_back(currentWord);
                    }
                }
                currentWord[i] = originalChar; // Reset character
            }
        }

        swap(beginSet, tempSet);
    }
}

// Helper function to perform DFS for finding paths
void dfsPaths(const string& word, const string& endWord, unordered_map<string, vector<string>>& parent, vector<string>& path, vector<vector<string>>& results) {
    if (word == endWord) {
        results.push_back(vector<string>(path.rbegin(), path.rend()));
        return;
    }
    for (const string& parentWord : parent[word]) {
        path.push_back(parentWord);
        dfsPaths(parentWord, endWord, parent, path, results);
        path.pop_back();
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    vector<vector<string>> results;
    if (!wordSet.count(endWord)) return results; // Return if endWord is not in wordList

    unordered_map<string, vector<string>> parent; // To store paths
    bfsLayers(beginWord, endWord, wordSet, parent);

    if (parent.find(endWord) == parent.end()) return results; // No path found

    vector<string> path = {endWord};
    dfsPaths(endWord, beginWord, parent, path, results);

    return results;
}

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    vector<vector<string>> ladders = findLadders(beginWord, endWord, wordList);

    cout << "All shortest transformation sequences:" << endl;
    for (const auto& ladder : ladders) {
        for (const string& word : ladder) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
