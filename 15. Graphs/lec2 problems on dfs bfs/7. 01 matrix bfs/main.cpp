// https://leetcode.com/problems/01-matrix/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> d(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j] == 0) {
                    d[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        while(!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for(int i=0; i<4; i++) {
                int nx = r + dx[i];
                int ny = c + dy[i];

                if(nx >= 0 and nx < m and ny >= 0 and ny < n and d[nx][ny] > d[r][c] + 1) {
                    d[nx][ny] = d[r][c] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return d;
    }
};