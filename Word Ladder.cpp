#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int wordLadderLength(string beginWord, string endWord, vector<string>& wordList) {
    // Step 1: Create a set of words from the word list
    unordered_set<string> wordSet(wordList.begin(), wordList.end());

    // If the endWord is not in the list, return 0 (no transformation possible)
    if (wordSet.find(endWord) == wordSet.end()) {
        return 0;
    }

    // Step 2: Queue for BFS and insert beginWord
    queue<pair<string, int>> q;
    q.push({beginWord, 1}); // {current word, current length of the sequence}

    // Step 3: BFS
    while (!q.empty()) {
        string currentWord = q.front().first;
        int currentLength = q.front().second;
        q.pop();

        // Try changing each character of the current word
        for (int i = 0; i < currentWord.size(); ++i) {
            char originalChar = currentWord[i];

            // Try all possible one-letter transformations
            for (char c = 'a'; c <= 'z'; ++c) {
                if (c == originalChar) continue; // Skip the same character

                currentWord[i] = c;
                
                // If the transformed word is the endWord, return the sequence length
                if (currentWord == endWord) {
                    return currentLength + 1;
                }

                // If the transformed word is in the wordSet, add it to the queue
                if (wordSet.find(currentWord) != wordSet.end()) {
                    q.push({currentWord, currentLength + 1});
                    wordSet.erase(currentWord); // Remove word from the set to prevent revisiting
                }
            }

            // Restore the original character
            currentWord[i] = originalChar;
        }
    }

    // No transformation sequence found
    return 0;
}

int main() {
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    string beginWord = "hit";
    string endWord = "cog";

    int ladderLength = wordLadderLength(beginWord, endWord, wordList);

    if (ladderLength > 0) {
        cout << "The length of the shortest transformation sequence is: " << ladderLength << endl;
    } else {
        cout << "No transformation sequence exists." << endl;
    }

    return 0;
}
