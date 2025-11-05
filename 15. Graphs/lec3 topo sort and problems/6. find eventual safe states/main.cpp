// https://leetcode.com/problems/find-eventual-safe-states/description/

// https://takeuforward.org/data-structure/find-eventual-safe-states-bfs-topological-sort-g-25/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        unordered_map<int, vector<int>> mpp;

        vector<int> indegreeOdReversedGraph(n, 0);
        vector<int> ans;

        for (int u = 0; u < n; u++) {
            for (int v : graph[u]) {
                mpp[v].push_back(u);
                indegreeOdReversedGraph[u]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegreeOdReversedGraph[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int ele = q.front();
            q.pop();
            ans.push_back(ele);

            for (auto neighbor : mpp[ele]) {
                indegreeOdReversedGraph[neighbor]--;
                if (indegreeOdReversedGraph[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
