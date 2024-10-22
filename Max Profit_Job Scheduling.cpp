#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Job struct to store start time, end time, and profit of each job
struct Job {
    int startTime;
    int endTime;
    int profit;
};

// Binary search helper function to find the latest job that doesn't conflict with the current job
int findNonConflictingJob(const vector<Job>& jobs, int currentIndex) {
    int low = 0, high = currentIndex - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (jobs[mid].endTime <= jobs[currentIndex].startTime) {
            if (jobs[mid + 1].endTime <= jobs[currentIndex].startTime) {
                low = mid + 1;
            } else {
                return mid;
            }
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int n = startTime.size();
    
    // Store jobs in a vector of Job structs
    vector<Job> jobs(n);
    for (int i = 0; i < n; ++i) {
        jobs[i] = {startTime[i], endTime[i], profit[i]};
    }
    
    // Sort jobs by their end time
    sort(jobs.begin(), jobs.end(), [](Job& a, Job& b) {
        return a.endTime < b.endTime;
    });
    
    // DP array to store the maximum profit until the ith job
    vector<int> dp(n, 0);
    
    dp[0] = jobs[0].profit; // The first job can be taken on its own

    // Fill the dp array
    for (int i = 1; i < n; ++i) {
        // Include the current job
        int includeProfit = jobs[i].profit;
        
        // Find the last non-conflicting job
        int nonConflictingJob = findNonConflictingJob(jobs, i);
        if (nonConflictingJob != -1) {
            includeProfit += dp[nonConflictingJob];
        }
        
        // Maximum profit of including or not including the current job
        dp[i] = max(dp[i - 1], includeProfit);
    }
    
    // The answer is the maximum profit achievable by scheduling jobs
    return dp[n - 1];
}

int main() {
    vector<int> startTime = {1, 2, 3, 4, 6};
    vector<int> endTime = {3, 5, 10, 6, 9};
    vector<int> profit = {20, 20, 100, 70, 60};
    
    cout << "Maximum Profit: " << jobScheduling(startTime, endTime, profit) << endl;
    
    return 0;
}
