// https://leetcode.com/problems/map-of-highest-peak/description/

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> h(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    h[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && h[nx][ny] == -1) {
                    h[nx][ny] = h[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return h;
    }
};


/*

complexity analysis =>

time => o(n *m + n * m * 4) => the bfs function will be called for n x m nodes a d for every node, we are traversing the 4 neighbours

space complexity => o(n x m) + o(n x m) + o(n x m) , for the visited arat, distance matriux and queue space => each taking n x m

*/