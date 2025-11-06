// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/

// https://takeuforward.org/data-structure/g-40-number-of-ways-to-arrive-at-destination/


class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<int>pathWays(n, 0);
        vector<long long>dist(n, LLONG_MAX);
        vector<vector<pair<int, int>>>adj(n);
        for(auto it: roads){
            int u = it[0];
            int v = it[1];
            long long wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>>pq;
        pq.push({0, 0});
        dist[0] = 0;
        pathWays[0] = 1;
        int mod = 1e9 + 7;

        while(!pq.empty()){
            auto it = pq.top();
            int node = it.second;
            long long dt = it.first;
            pq.pop();

            if(dt > dist[node]) continue;
            
            for(auto i: adj[node]){
                int adjNode = i.first;
                long long wt = i.second;
                if(dist[adjNode] > (dt + wt)){
                    dist[adjNode] = (dt + wt);
                    pathWays[adjNode] = (pathWays[node]);
                    pq.push({dist[adjNode], adjNode});
                }
                else if(dist[adjNode] == (dt + wt)){
                    pathWays[adjNode] = (pathWays[node] + pathWays[adjNode]) % mod;
                }
            }
        }
        return pathWays[n - 1] % mod;
    }
};