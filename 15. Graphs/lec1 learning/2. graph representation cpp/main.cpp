// https://takeuforward.org/graph/graph-representation-in-c/

// https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=print-adjacency-list

class Solution {
    public:
      // Function to return the adjacency list for each vertex.
      vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
          // Code here
          vector<vector<int>> g(V);
          for(int i=0; i<edges.size(); i++){
              g[edges[i].first].push_back(edges[i].second);
              g[edges[i].second].push_back(edges[i].first);
          }
          return g;
          
      }
  };