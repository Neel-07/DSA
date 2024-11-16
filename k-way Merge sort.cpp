#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
    int data;
    int arrayIdx;
    int elementIdx;

    Node(int data, int arrayIdx, int elementIdx) {
        this->data = data;
        this->arrayIdx = arrayIdx;
        this->elementIdx = elementIdx;
    }
};

struct compare {
    bool operator()(Node const& p1, Node const& p2) {
        return p1.data > p2.data;
    }
};

vector<int> mergeKArrays(vector<vector<int>>& arr) {
    int k = arr.size();
    priority_queue<Node, vector<Node>, compare> pq;

    // Push the first element of each array into the heap
    for (int i = 0; i < k; i++) {
        pq.push(Node(arr[i][0], i, 0));
    }

    vector<int> merged;
    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();

        merged.push_back(node.data);

        // If there are more elements in the array, push the next element
        if (node.elementIdx + 1 < arr[node.arrayIdx].size()) {
            pq.push(Node(arr[node.arrayIdx][node.elementIdx + 1], node.arrayIdx, node.elementIdx + 1));
        }
    }

    return merged;
}

int main() {
    vector<vector<int>> arr = {{1, 3, 5, 7}, {2, 4, 6, 8}, {0, 9, 10, 11}};
    vector<int> merged = mergeKArrays(arr);

    for (int num : merged) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}