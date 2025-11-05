// https://leetcode.com/problems/word-ladder-ii/description/

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        unordered_set<string> st(wordList.begin(), wordList.end());
        vector<vector<string>> ans;

        if(st.find(endWord) == st.end()) return ans;

        queue<vector<string>> q; 
        q.push({beginWord});

        unordered_set<string> usedOnLevel;
        int level = 1;
        int minLevel = INT_MAX;

        while(!q.empty()) {
            vector<string> path = q.front();
            q.pop();
            
            if(path.size() > level) {
                for(auto &w : usedOnLevel) st.erase(w);
                usedOnLevel.clear();
                level = path.size();
                if(level > minLevel) break; // stop if we've already found the shortest paths
            }

            string word = path.back();

            if(word == endWord) {
                minLevel = level;
                ans.push_back(path);
                continue;
            }

            for(int i = 0; i < word.size(); i++) {
                char org = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if(st.find(word) != st.end()) {
                        vector<string> newPath = path;
                        newPath.push_back(word);
                        q.push(newPath);
                        usedOnLevel.insert(word);
                    }
                }
                word[i] = org;
            }
        }
        return ans;
    }
};
