// https://takeuforward.org/data-structure/detect-a-cycle-in-directed-graph-topological-sort-kahns-algorithm-g-23

// https://leetcode.com/problems/course-schedule/description/

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



/*
Complexity analysis => 

Time complexity: ( O(V + E) )
    We visit each node and edge once.

Space complexity: ( O(V + E) )
    For the adjacency list, in-degree array, and queue.

*/