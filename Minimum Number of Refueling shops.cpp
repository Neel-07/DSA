#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    priority_queue<int> maxHeap; // Max heap to store fuel at past stations
    int currentFuel = startFuel;
    int refuels = 0;
    int prevPosition = 0;
    
    for (auto& station : stations) {
        int position = station[0];
        int fuel = station[1];
        
        // Travel to the station, refueling as needed
        currentFuel -= position - prevPosition;
        while (!maxHeap.empty() && currentFuel < 0) {
            currentFuel += maxHeap.top();
            maxHeap.pop();
            refuels++;
        }
        
        if (currentFuel < 0) return -1; // Cannot reach this station
        
        maxHeap.push(fuel);
        prevPosition = position;
    }
    
    // Travel to the target, refueling as needed
    currentFuel -= target - prevPosition;
    while (!maxHeap.empty() && currentFuel < 0) {
        currentFuel += maxHeap.top();
        maxHeap.pop();
        refuels++;
    }
    
    return currentFuel < 0 ? -1 : refuels;
}

int main() {
    int target = 100;
    int startFuel = 10;
    vector<vector<int>> stations = {{10, 60}, {20, 30}, {30, 30}, {60, 40}};
    
    cout << "Minimum refueling stops: " << minRefuelStops(target, startFuel, stations) << endl;
    return 0;
}
