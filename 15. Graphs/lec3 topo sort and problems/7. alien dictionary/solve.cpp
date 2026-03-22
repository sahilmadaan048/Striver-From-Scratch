// https://www.geeksforgeeks.org/problems/alien-dictionary/1

// https://takeuforward.org/data-structure/alien-dictionary-topological-sort-g-26'

// https://www.geeksforgeeks.org/problems/alien-dictionary/1

class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        vector<vector<int>> graph(26);
        vector<int> indegree(26, 0);
        vector<bool> present(26, false);
        
        for(auto word: words) {
            for(auto ch: word) {
                present[ch-'a'] = true;
            }
        }
        
        for(int i=1; i<words.size(); i++) {
            int j = 0;
            int len = min(words[i].size(), words[i-1].size());
            
            while(j < len and words[i][j] == words[i-1][j]) {
                j++;
            }
            
            if(j == len and words[i-1].size() > words[i].size()) {
                return "";
            }
            
            if(j < len) {
                int u = words[i-1][j] - 'a';
                int v = words[i][j] - 'a';
                
                graph[u].push_back(v);
                indegree[v]++;
            }
        }
        
        queue<int> q;
        int count = 0;
        for(int i=0; i<26; i++) {
            if(present[i]) {
                count++;
                if(indegree[i] == 0) {
                    q.push(i);
                }
            }
        }
        
        
        string order;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            order += char(node + 'a');
            
            for(int it: graph[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        if(order.size() != count) {
            return "";
        }
        
        return order;
    }
};

/*

Complexity analysis

time complexity => O(N⋅L+K+E)

space complexity  => O(K+E)​≈O(26+N)≈O(N)

*/