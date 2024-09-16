#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int parent, vector<int> adj[], vector<bool>& visited) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, visited))
                return true;
        } else if (neighbor != parent) {
            return true;
        }
    }
    return false;
}

bool hasCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited))
                return true;
        }
    }
    return false;
}

int main() {
    int V = 5;
    vector<int> adj[V];

    // Add edges to the graph
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[4].push_back(1);
    adj[1].push_back(4);

    if (hasCycle(V, adj))
        cout << "Cycle exists\n";
    else
        cout << "No cycle exists\n";

    return 0;
}
