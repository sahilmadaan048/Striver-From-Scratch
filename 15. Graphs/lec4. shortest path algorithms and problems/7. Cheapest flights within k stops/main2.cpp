class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adj; 
        for (auto &f : flights) {
            int u = f[0], v = f[1], wt = f[2];
            adj[u].push_back({v, wt});
        }

        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while (!q.empty()) {
            auto [stops, nodeCost] = q.front();
            q.pop();
            int node = nodeCost.first;
            int cost = nodeCost.second;

            if (stops > k) continue;

            for (auto &[nbr, wt] : adj[node]) {
                if (cost + wt < dist[nbr] && stops <= k) {
                    dist[nbr] = cost + wt;
                    q.push({stops + 1, {nbr, dist[nbr]}});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
