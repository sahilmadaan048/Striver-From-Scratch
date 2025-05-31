// https://takeuforward.org/data-structure/n-meetings-in-one-room/

// https://takeuforward.org/plus/dsa/problems/n-meetings-in-one-room

// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

class Solution {
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<pair<int,int>> interval;

        // Store the meetings as (end_time, start_time)
        for(int i = 0; i < n; i++) {
            interval.push_back({end[i], start[i]});
        }

        // Sort meetings based on end time
        sort(interval.begin(), interval.end());

        int cnt = 1; // Count the first meeting
        int last_end = interval[0].first;

        for(int i = 1; i < n; i++) {
            if(interval[i].second > last_end) {
                cnt++;
                last_end = interval[i].first;
            }
        }

        return cnt;
    }
};

/*



ime Complexity: O(n) to iterate through every position and insert them in a data structure. O(n log n)  to sort the data structure in ascending order of end time. O(n)  to iterate through the positions and check which meeting can be performed.

Overall : O(n) +O(n log n) + O(n) ~O(n log n)

Space Complexity: O(n)  since we used an additional data structure for storing the start time, end time, and meeting no.

*/