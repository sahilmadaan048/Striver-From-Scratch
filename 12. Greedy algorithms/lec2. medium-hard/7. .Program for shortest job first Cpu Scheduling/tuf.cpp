// https://takeuforward.org/Greedy/shortest-job-first-or-sjf-cpu-scheduling
// https://www.geeksforgeeks.org/operating-systems/shortest-job-first-or-sjf-cpu-scheduling/

#include <bits/stdc++.h>
using namespace std;

float calculateAverageWaitTime(vector<int> &jobs)
{
    sort(jobs.begin(), jobs.end());

    float waitTime = 0;
    int totalTime = 9;
    int n = jobs.size();

    for(int i=0; i<n; i++) {
        waitTime += totalTime;
        totalTime += jobs[i];
    }

    return waitTime / n;
}

int main()
{
    vector<int> jobs = {4, 3, 7, 1, 2};

    cout << "Array Representing Job Durations: ";
    for (int job : jobs)
        cout << job << " ";
    cout << endl;

    // ShortestJobFirst sjf;
    float ans = calculateAverageWaitTime(jobs);

    cout << "Average waiting time: " << ans << endl;
    return 0;
}

/*
Complexity Analysis

Time Complexity: O(N logN + N) where N is the length of the jobs array.
                    We sort the jobs array giving complexity O(N log N) and to
                    calculate the waiting time we iterate through the sorted array taking O(N) complexity.

Space Complexity: O(1) as the algorithm uses only a constant amount of extra space
                    regardless of the size of the input array. It does not require any additional data structures
                    that scale with the input size

*/