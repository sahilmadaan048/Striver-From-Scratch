// https://leetcode.com/problems/path-with-minimum-effort/description/

// https://takeuforward.org/data-structure/g-37-path-with-minimum-effort/

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;

        using state = pair<int, pair<int, int>>; 
        priority_queue<state, vector<state>, greater<state>> pq;
        pq.push({0, {0, 0}});

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        while (!pq.empty()) {
            auto [d, cell] = pq.top();
            pq.pop();

            int r = cell.first;
            int c = cell.second;

            if (d > dist[r][c]) continue;

            if (r == m - 1 && c == n - 1)
                return d;

            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int diff = abs(grid[nr][nc] - grid[r][c]);
                    int newEffort = max(d, diff);

                    if (newEffort < dist[nr][nc]) {
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};
