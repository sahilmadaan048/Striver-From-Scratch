// https://leetcode.com/problems/number-of-enclaves/description/

// https://takeuforward.org/graph/number-of-enclaves

class Solution
{
public:
    int bfs(vector<vector<int>> &grid, vector<vector<bool>> &vis, int i,
            int j, int n, int m)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = true;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        int cnt = 1;
        bool found = false;

        // check if yhe statrting cell is on the boundary
        if (i == 0 or j == 0 or i == n - 1 or j == m - 1)
        {
            found = true;
        }

        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 and nx < n and ny >= 0 and ny < m and !vis[nx][ny] and
                    grid[nx][ny] == 1)
                {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                    cnt++;

                    if (nx == 0 || ny == 0 || nx == n - 1 || ny == m - 1)
                    {
                        found = true;
                    }
                }
            }
        }

        return found ? 0 : cnt;
    }
    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] and grid[i][j] == 1)
                {
                    ans += bfs(grid, vis, i, j, n, m);
                }
            }
        }
        return ans;
    }
};

/*

Complexity Analysis

Time Complexity: O(n × m), where n is the number of rows and m is the number of columns. Each cell is processed at most once.

Space Complexity: O(n × m), due to the vis array and BFS queue in the worst case.

*/