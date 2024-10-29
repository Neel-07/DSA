#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list for the original graph
    vector<vector<int>> adjRev; // Adjacency list for the transposed graph

    // Helper function for DFS on the original graph
    void dfs1(int v, vector<bool>& visited, stack<int>& finishStack) {
        visited[v] = true;
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                dfs1(neighbor, visited, finishStack);
            }
        }
        // After DFS from v, push it onto the finish stack
        finishStack.push(v);
    }

    // Helper function for DFS on the transposed graph
    void dfs2(int v, vector<bool>& visited, vector<int>& component) {
        visited[v] = true;
        component.push_back(v); // Add node to current SCC
        for (int neighbor : adjRev[v]) {
            if (!visited[neighbor]) {
                dfs2(neighbor, visited, component);
            }
        }
    }

public:
    // Constructor to initialize graph with V vertices
    Graph(int V) : V(V), adj(V), adjRev(V) {}

    // Function to add a directed edge from u to v
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adjRev[v].push_back(u); // Reverse edge for the transposed graph
    }

    // Function to find all SCCs
    vector<vector<int>> findSCCs() {
        vector<bool> visited(V, false);
        stack<int> finishStack;

        // Step 1: Perform DFS on the original graph and push vertices onto finishStack by finish time
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs1(i, visited, finishStack);
            }
        }

        // Step 2: Reset visited array for the second DFS on the transposed graph
        fill(visited.begin(), visited.end(), false);
        vector<vector<int>> sccs; // To store all SCCs

        // Step 3: Process nodes in order of decreasing finish times
        while (!finishStack.empty()) {
            int v = finishStack.top();
            finishStack.pop();

            // If this node hasn't been visited in the second DFS, it's the start of a new SCC
            if (!visited[v]) {
                vector<int> component;
                dfs2(v, visited, component);
                sccs.push_back(component); // Add SCC to the list of SCCs
            }
        }

        return sccs;
    }
};

int main() {
    // Example usage:
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    vector<vector<int>> sccs = g.findSCCs();

    cout << "Strongly Connected Components:\n";
    for (const auto& component : sccs) {
        for (int v : component) {
            cout << v << " ";
        }
        cout << "\n";
    }

    return 0;
}
