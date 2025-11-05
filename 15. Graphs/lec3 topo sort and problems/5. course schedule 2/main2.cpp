// https://leetcode.com/problems/course-schedule-iii/description/

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        // dort on the absis of end time
        sort(courses.begin(), courses.end(), [&](const auto & a, const auto & b) {
            return a[1] < b[1];
        }); 
        priority_queue<int> pq;
        long long time = 0;
        for(auto it: courses) {
            time += it[0];
            pq.push(it[0]);
            if(time > it[1]) {
                time -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};