// https://leetcode.com/problems/non-overlapping-intervals/submissions/1930557234/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](const auto &a, const auto &b) {
            return a[0] < b[0];
        });

        int n = intervals.size();
        int cnt = 0;

        vector<int> prev = intervals[0];

        for(int i=1; i<n; i++) {
            vector<int> curr = intervals[i];

            if(curr[0] < prev[1]) {
                cnt++;
                if(curr[1] < prev[1]) {
                    prev = curr;
                }
            } else {
                prev = curr;
            }
        }
        
        return cnt;
    }
};