#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findArticulationPoints(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& discovery, vector<int>& low, vector<int>& parent, vector<bool>& articulationPoints, int& time) {
    // Count discovery time of the current node
    visited[u] = true;
    discovery[u] = low[u] = ++time;
    int children = 0; // Count of children in DFS tree
    
    for (int v : adj[u]) {
        if (!visited[v]) { // If v is not visited
            parent[v] = u;
            children++;
            findArticulationPoints(v, adj, visited, discovery, low, parent, articulationPoints, time);

            // Check if the subtree rooted at v has a connection back to one of the ancestors of u
            low[u] = min(low[u], low[v]);

            // u is an articulation point in following cases:

            // (1) u is root of DFS tree and has two or more children
            if (parent[u] == -1 && children > 1)
                articulationPoints[u] = true;

            // (2) u is not root and low value of one of its children is more than discovery value of u
            if (parent[u] != -1 && low[v] >= discovery[u])
                articulationPoints[u] = true;
                
        } else if (v != parent[u]) {
            // Update low value of u for parent function calls
            low[u] = min(low[u], discovery[v]);
        }
    }
}

vector<int> getArticulationPoints(int numVertices, vector<vector<int>>& edges) {
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
    vector<int> parent(numVertices, -1);
    vector<bool> articulationPoints(numVertices, false);

    int time = 0;
    for (int i = 0; i < numVertices; i++) {
        if (!visited[i]) {
            findArticulationPoints(i, adj, visited, discovery, low, parent, articulationPoints, time);
        }
    }

    // Collect all articulation points
    vector<int> result;
    for (int i = 0; i < numVertices; i++) {
        if (articulationPoints[i]) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    int numVertices = 5;
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {1, 2}, {1, 3}, {3, 4}
    };

    vector<int> articulationPoints = getArticulationPoints(numVertices, edges);
    
    cout << "Articulation points in the graph are: ";
    for (int point : articulationPoints) {
        cout << point << " ";
    }
    cout << endl;

    return 0;
}
