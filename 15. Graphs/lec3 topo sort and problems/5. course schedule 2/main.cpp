// https://leetcode.com/problems/course-schedule-ii/description/

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> indegree(n, 0);
        unordered_map<int, vector<int>> mp;


        for(auto it: prerequisites) {
            int course = it[0];
            int pre = it[1];
            mp[pre].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        for(int i=0; i<n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(auto it: mp[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        if(topo.size() == n) return topo;
        return {};
    }
};


/*
 Complexity analysis

 Time Complexity: ( O(V + E) )
We visit every node and edge once.

Space Complexity: ( O(V + E) )
For storing the adjacency list, indegree array, and queue

*/