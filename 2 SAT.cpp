#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class TwoSAT {
    int n;
    vector<vector<int>> adj, adjRev;
    vector<bool> visited;
    vector<int> component, assignment;
    stack<int> finishStack;

public:
    TwoSAT(int numVars) : n(numVars) {
        adj.resize(2 * n);
        adjRev.resize(2 * n);
        visited.resize(2 * n, false);
        component.resize(2 * n, -1);
        assignment.resize(n, false);
    }

    int varIndex(int var) {
        return var > 0 ? (var - 1) * 2 : (-var - 1) * 2 + 1;
    }

    void addClause(int x, int y) {
        int xIndex = varIndex(x);
        int yIndex = varIndex(y);
        int notX = xIndex ^ 1;
        int notY = yIndex ^ 1;

        adj[notX].push_back(yIndex); // ¬x → y
        adj[notY].push_back(xIndex); // ¬y → x
        adjRev[yIndex].push_back(notX);
        adjRev[xIndex].push_back(notY);
    }

    void dfs1(int v) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u]) dfs1(u);
        }
        finishStack.push(v);
    }

    void dfs2(int v, int comp) {
        component[v] = comp;
        for (int u : adjRev[v]) {
            if (component[u] == -1) dfs2(u, comp);
        }
    }

    bool solve() {
        // Step 1: First DFS to fill finish stack
        for (int i = 0; i < 2 * n; ++i) {
            if (!visited[i]) dfs1(i);
        }

        // Step 2: Reverse DFS to assign components
        int comp = 0;
        while (!finishStack.empty()) {
            int v = finishStack.top();
            finishStack.pop();
            if (component[v] == -1) {
                dfs2(v, comp++);
            }
        }

        // Step 3: Check for contradictions and assign truth values
        for (int i = 0; i < n; ++i) {
            if (component[2 * i] == component[2 * i + 1]) {
                return false; // Unsatisfiable
            }
            assignment[i] = (component[2 * i] > component[2 * i + 1]);
        }
        return true; // Satisfiable
    }

    vector<bool> getAssignment() const {
        return assignment;
    }
};

int main() {
    int numVars = 3; // Number of variables
    TwoSAT solver(numVars);

    // Example clauses: (x1 ∨ x2), (¬x1 ∨ x3), (¬x2 ∨ ¬x3)
    solver.addClause(1, 2);
    solver.addClause(-1, 3);
    solver.addClause(-2, -3);

    if (solver.solve()) {
        cout << "Satisfiable assignment found:" << endl;
        vector<bool> assignment = solver.getAssignment();
        for (int i = 0; i < numVars; ++i) {
            cout << "x" << i + 1 << " = " << (assignment[i] ? "True" : "False") << endl;
        }
    } else {
        cout << "No satisfiable assignment exists." << endl;
    }

    return 0;
}
