// https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

// https://takeuforward.org/data-structure/g-36-shortest-distance-in-a-binary-maze/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][0] == 1 || grid[m-1][n-1] == 1)
            return -1;

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 1; 

        using state = pair<int, pair<int, int>>; 
        priority_queue<state, vector<state>, greater<state>> pq;
        pq.push({1, {0, 0}});

        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!pq.empty()) {
            auto [d, cell] = pq.top();
            pq.pop();
            int r = cell.first, c = cell.second;

            if (d > dist[r][c]) continue;

            if (r == m - 1 && c == n - 1)
                return d;

            for (int i = 0; i < 8; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                    if (d + 1 < dist[nr][nc]) {
                        dist[nr][nc] = d + 1;
                        pq.push({dist[nr][nc], {nr, nc}});
                    }
                }
            }
        }
        return -1;
    }
};
