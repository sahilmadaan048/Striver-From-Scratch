// https://leetcode.com/problems/cheapest-flights-within-k-stops/

// https://takeuforward.org/data-structure/g-38-cheapest-flights-within-k-stops/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto &f : flights) {
            int u = f[0], v = f[1], wt = f[2];
            adj[u].push_back({v, wt});
        }

        using state = tuple<int, int, int>; 
        priority_queue<state, vector<state>, greater<state>> pq;

        vector<int> dist(n, INT_MAX);
        pq.push({0, src, 0});
        dist[src] = 0;

        while (!pq.empty()) {
            auto [cost, node, stops] = pq.top();
            pq.pop();

            if (node == dst) return cost;

            if (stops > k) continue;

            for (auto &[next, price] : adj[node]) {
                int newCost = cost + price;

                if (newCost < dist[next] || stops < k) {
                    dist[next] = newCost;
                    pq.push({newCost, next, stops + 1});
                }
            }
        }

        return -1;
    }
};
