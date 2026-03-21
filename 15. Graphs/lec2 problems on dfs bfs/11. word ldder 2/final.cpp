class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> adj;

    void dfs(string word, vector<string>& path) {
        if (adj[word].empty()) {
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }

        for (auto &prev : adj[word]) {
            path.push_back(prev);
            dfs(prev, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (!st.count(endWord)) return {};

        unordered_map<string, int> level;
        queue<string> q;

        q.push(beginWord);
        level[beginWord] = 0;

        int wordLen = beginWord.size();

        // BFS
        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int currLevel = level[word];

            for (int i = 0; i < wordLen; i++) {
                string temp = word;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    temp[i] = ch;

                    if (st.count(temp)) {
                        if (!level.count(temp)) {
                            level[temp] = currLevel + 1;
                            q.push(temp);
                            adj[temp].push_back(word);
                        }
                        else if (level[temp] == currLevel + 1) {
                            adj[temp].push_back(word);
                        }
                    }
                }
            }
        }

        if (!level.count(endWord)) return {};

        vector<string> path = {endWord};
        dfs(endWord, path);

        return ans;
    }
};