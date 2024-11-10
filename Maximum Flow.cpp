#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class MaxFlow {
public:
    MaxFlow(int vertices) : vertices(vertices) {
        capacity = vector<vector<int>>(vertices, vector<int>(vertices, 0));
        adj = vector<vector<int>>(vertices);
    }

    void addEdge(int u, int v, int cap) {
        capacity[u][v] = cap;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int findMaxFlow(int source, int sink) {
        int maxFlow = 0;
        vector<int> parent(vertices);

        // While there exists an augmenting path, add flow.
        while (bfs(source, sink, parent)) {
            int pathFlow = INT_MAX;

            // Find the maximum flow through the path found.
            for (int v = sink; v != source; v = parent[v]) {
                int u = parent[v];
                pathFlow = min(pathFlow, capacity[u][v]);
            }

            // Update residual capacities of the edges and reverse edges.
            for (int v = sink; v != source; v = parent[v]) {
                int u = parent[v];
                capacity[u][v] -= pathFlow;
                capacity[v][u] += pathFlow;
            }

            // Add path flow to the overall flow.
            maxFlow += pathFlow;
        }

        return maxFlow;
    }

private:
    int vertices;
    vector<vector<int>> capacity;  // Capacity matrix
    vector<vector<int>> adj;       // Adjacency list

    bool bfs(int source, int sink, vector<int>& parent) {
        fill(parent.begin(), parent.end(), -1);
        parent[source] = -1;
        queue<pair<int, int>> q;
        q.push({source, INT_MAX});

        while (!q.empty()) {
            int u = q.front().first;
            int flow = q.front().second;
            q.pop();

            for (int v : adj[u]) {
                if (parent[v] == -1 && capacity[u][v] > 0) {  // If not visited and capacity is available
                    parent[v] = u;
                    int newFlow = min(flow, capacity[u][v]);
                    if (v == sink)
                        return true;  // If we reached the sink node

                    q.push({v, newFlow});
                }
            }
        }

        return false;
    }
};

int main() {
    int vertices = 6;
    MaxFlow maxFlow(vertices);

    // Example: add edges with capacities
    maxFlow.addEdge(0, 1, 16);
    maxFlow.addEdge(0, 2, 13);
    maxFlow.addEdge(1, 2, 10);
    maxFlow.addEdge(1, 3, 12);
    maxFlow.addEdge(2, 1, 4);
    maxFlow.addEdge(2, 4, 14);
    maxFlow.addEdge(3, 2, 9);
    maxFlow.addEdge(3, 5, 20);
    maxFlow.addEdge(4, 3, 7);
    maxFlow.addEdge(4, 5, 4);

    cout << "The maximum flow is: " << maxFlow.findMaxFlow(0, 5) << endl;

    return 0;
}
