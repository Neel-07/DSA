#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int src, int V, vector<int> adj[]) {
    vector<int> dist(V, -1);  // Distance array initialized with -1
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) {  // If not visited
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    // Print shortest distances
    for (int i = 0; i < V; i++) {
        cout << "0 -> " << i << " = " << dist[i] << endl;
    }
}

int main() {
    int V = 6;
    vector<int> adj[V];

    // Add edges to the graph
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[2].push_back(4);
    adj[4].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[3].push_back(5);
    adj[5].push_back(3);

    int src = 0;
    bfs(src, V, adj);

    return 0;
}
