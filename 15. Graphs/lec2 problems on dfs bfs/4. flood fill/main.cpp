// https://leetcode.com/problems/flood-fill/description/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        if(image[sr][sc] == color) return image;

        vector<vector<int>> ans = image;
        ans[sr][sc] = color;

        queue<pair<int, int>> q;
        q.push({sr, sc});

        while(!q.empty()) {
            auto x = q.front().first;
            auto y = q.front().second;
            q.pop();


            int dx[4] = {-1, 0, 1, 0};
            int dy[4] = {0, 1, 0,  -1};

            for(int i=0; i<4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 and nx < m and ny >= 0 and ny < n and !vis[nx][ny] and ans[nx][ny] != color and image[nx][ny] == image[sr][sc]) {
                    vis[nx][ny] = 1;
                    ans[nx][ny] = color;
                    q.push({nx, ny});
                }
            }
        }

        return ans;        
    }
};