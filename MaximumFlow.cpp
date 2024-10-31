#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>

using namespace std;

// Function to perform BFS and find an augmenting path from source to sink
bool bfs(const vector<vector<int>>& residualGraph, int source, int sink, vector<int>& parent) {
    int n = residualGraph.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v = 0; v < n; v++) {
            // If there is available capacity and v has not been visited
            if (!visited[v] && residualGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
                // If we reached the sink, return true
                if (v == sink) return true;
            }
        }
    }
    
    return false; // No augmenting path found
}

// Function to implement Edmonds-Karp algorithm and return the maximum flow
int edmondsKarp(int numVertices, vector<vector<int>>& capacityGraph, int source, int sink) {
    // Residual graph initially set to the capacity graph
    vector<vector<int>> residualGraph = capacityGraph;
    vector<int> parent(numVertices); // Array to store path
    int maxFlow = 0; // Initialize max flow to 0
    
    // Augment flow while there is a path from source to sink
    while (bfs(residualGraph, source, sink, parent)) {
        // Find the maximum flow through the path found by BFS
        int pathFlow = INT_MAX;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }
        
        // Update residual capacities of the edges and reverse edges along the path
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }
        
        // Add path flow to overall flow
        maxFlow += pathFlow;
    }
    
    return maxFlow;
}

int main() {
    // Number of vertices
    int numVertices = 6;
    // Capacity graph where each entry capacityGraph[u][v] indicates the capacity of edge u->v
    vector<vector<int>> capacityGraph = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };
    
    int source = 0, sink = 5;
    cout << "The maximum possible flow is " << edmondsKarp(numVertices, capacityGraph, source, sink) << endl;

    return 0;
}
