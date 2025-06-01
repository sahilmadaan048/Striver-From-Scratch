// https://takeuforward.org/Greedy/shortest-job-first-or-sjf-cpu-scheduling

                            
#include <vector>   
#include <algorithm>
#include <iostream>

using namespace std;

// Function to calculate average
// waiting time using Shortest
// Job First algorithm
float shortestJobFirst(vector<int> jobs) {
    // Sort the jobs in ascending order
    sort(jobs.begin(), jobs.end()); 

    // Initialize total waiting time
    float waitTime = 0; 
    // Initialize total time taken
    int totalTime = 0; 
    // Get the number of jobs
    int n = jobs.size(); 

    // Iterate through each job
    // to calculate waiting time
    for(int i = 0; i < n; ++i) {
        
        // Add current total
        // time to waiting time
        waitTime += totalTime; 
        
        // Add current job's
        // time to total time
        totalTime += jobs[i]; 
    }
    
    // Return the average waiting time
    return waitTime / n; 
}

int main() {
    vector<int> jobs = {4, 3, 7, 1, 2};
    
    cout << "Array Representing Job Durations: ";
    for(int i = 0; i < jobs.size(); i++){
        cout << jobs[i] << " ";
    }
    cout << endl;
    
    float ans = shortestJobFirst(jobs);
    cout << "Average waiting time: "<< ans;
    cout << endl;

    return 0;
}
                            
/*

Time Complexity: O(N logN + N) where N is the length of the jobs array. We sort the jobs array giving complexity O(N log N) and to calculate the waiting time we iterate through the sorted array taking O(N) complexity.

Space Complexity: O(1) as the algorithm uses only a constant amount of extra space regardless of the size of the input array. It does not require any additional data structures that scale with the input size.


*/