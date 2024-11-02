#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findBridges(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& discovery, vector<int>& low, int parent, vector<pair<int, int>>& bridges, int& time) {
    visited[u] = true;
    discovery[u] = low[u] = ++time;

    for (int v : adj[u]) {
        if (!visited[v]) { // v is not visited, so it's a child of u in the DFS tree
            findBridges(v, adj, visited, discovery, low, u, bridges, time);

            // Check if the subtree rooted at v has a back connection to one of the ancestors of u
            low[u] = min(low[u], low[v]);

            // If the lowest reachable vertex from v is above u, then u-v is a bridge
            if (low[v] > discovery[u]) {
                bridges.push_back({u, v});
            }
        } else if (v != parent) {
            // Update low[u] considering the back edge v-u
            low[u] = min(low[u], discovery[v]);
        }
    }
}

vector<pair<int, int>> getBridges(int numVertices, vector<vector<int>>& edges) {
    // Initialize adjacency list
    vector<vector<int>> adj(numVertices);
    for (const auto& edge : edges) {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(numVertices, false);
    vector<int> discovery(numVertices, -1);
    vector<int> low(numVertices, -1);
    vector<pair<int, int>> bridges;
    int time = 0;

    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            findBridges(i, adj, visited, discovery, low, -1, bridges, time);
        }
    }

    return bridges;
}

int main() {
    int numVertices = 5;
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {1, 2}, {1, 3}, {3, 4}
    };

    vector<pair<int, int>> bridges = getBridges(numVertices, edges);
    
    cout << "Bridges in the graph are:" << endl;
    for (const auto& bridge : bridges) {
        cout << bridge.first << " - " << bridge.second << endl;
    }

    return 0;
}
