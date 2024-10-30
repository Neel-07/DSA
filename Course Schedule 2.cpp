#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    // Step 1: Build the graph and the in-degree array
    vector<vector<int>> adj(numCourses);
    vector<int> inDegree(numCourses, 0);
    
    for (const auto& prereq : prerequisites) {
        int course = prereq[0];
        int prerequisite = prereq[1];
        adj[prerequisite].push_back(course);
        inDegree[course]++;
    }
    
    // Step 2: Initialize the queue with courses that have zero in-degree
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    // Step 3: Process the queue and build the course order
    vector<int> order;
    while (!q.empty()) {
        int course = q.front();
        q.pop();
        order.push_back(course);
        
        // Reduce the in-degree of each neighboring course
        for (int neighbor : adj[course]) {
            inDegree[neighbor]--;
            // If in-degree becomes zero, add to the queue
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    // Step 4: Check if the order contains all courses
    if (order.size() == numCourses) {
        return order; // Valid course order
    } else {
        return {}; // Cycle detected, return empty array
    }
}

int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

    vector<int> courseOrder = findOrder(numCourses, prerequisites);

    if (courseOrder.empty()) {
        cout << "It's impossible to complete all courses." << endl;
    } else {
        cout << "Course order to complete all courses: ";
        for (int course : courseOrder) {
            cout << course << " ";
        }
        cout << endl;
    }

    return 0;
}
