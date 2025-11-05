// https://leetcode.com/problems/network-delay-time/description/

// https://takeuforward.org/data-structure/network-delay-time

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for( auto time : times){
            adj[time[0]].push_back({time[1],time[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>>pq;
        pq.push({0,k});

        vector<int>dist(n+1, 1e9);
        dist[k] = 0;
        while( !pq.empty()){
            auto [cost, node] = pq.top();
            pq.pop();

            for(auto &[adjnode, weight] : adj[node]){
                if( cost+weight < dist[adjnode] ){
                    dist[adjnode] = weight+cost;
                    pq.push({weight+cost , adjnode});
                }
            }
        }

        int max_dist =0;
        for( int i =1; i<n+1; i++){
            if( dist[i] == 1e9)return -1;    // check if there is unvisited node preseent then return -1
            max_dist = max( max_dist, dist[i]);
        }
        return max_dist;
    }
};