// https://leetcode.com/problems/course-schedule/

// https://takeuforward.org/data-structure/course-schedule-i-and-ii-pre-requisite-tasks-topological-sort-g-24/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> mpp;

        for (auto& vec : prerequisites) {
            mpp[vec[1]].push_back(vec[0]);
        }

        vector<int> in(numCourses, 0);

        for (auto& [u, vec] : mpp) {
            for (auto v : vec) {
                in[v]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (in[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        // Kahn's algorithm (BFS)
        while (!q.empty()) {
            int node = q.front(); q.pop();
            count++;

            for (auto it : mpp[node]) {
                in[it]--;
                if (in[it] == 0) {
                    q.push(it);
                }
            }
        }
        return count == numCourses;
    }
};
