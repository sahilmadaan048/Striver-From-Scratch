// https://leetcode.com/problems/non-overlapping-intervals/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](const auto & a,  const auto &b) {
            return a[0] < b[0];
        });

        int n = intervals.size();
        int cnt = 0;
        vector<int> prev = intervals[0];
        for(int i = 1; i < n; i++) {
            vector<int> interval = intervals[i];

            if(interval[0] < prev[1]) {
                cnt++;
                // Keep the interval with the smaller end to reduce future overlaps
                if(interval[1] < prev[1]) {
                    prev = interval;
                }
            } else {
                prev = interval;
            }
        }

        return cnt;
    }
};