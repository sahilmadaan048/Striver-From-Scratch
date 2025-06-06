// https://www.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-provinces

class Solution {
    private:
        void dfs(int node, vector<vector<int>>& adjLs, vector<int>& vis) {
            vis[node] = 1;
            for (auto it : adjLs[node]) {
                if (!vis[it]) {
                    dfs(it, adjLs, vis);
                }
            }
        }
    
  public:
    int numProvinces(vector<vector<int>> isConnected, int V) {
        // code here
            int size = isConnected.size();
            vector<vector<int>> adj(size);
            for(int i= 0;i<size; i++){
                for(int j=0;j<size; j++){
                    if(isConnected[i][j] == 1 && (i != j)){
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                }
            }
    
            //now we have converted the adj matrix into adjj list
            vector<int> vis(size,0);
            int count = 0 ;
            for(int i=0;i<size;i++){
                if(!vis[i]){
                    count ++;
                    dfs(i,adj,vis);
                }
            }
            return count;
    }
};
