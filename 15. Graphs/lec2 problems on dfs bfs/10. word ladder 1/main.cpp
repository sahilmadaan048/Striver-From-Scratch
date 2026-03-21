// https://leetcode.com/problems/word-ladder/

// https://takeuforward.org/graph/word-ladder-i-g-29

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        queue<pair<string, int>> q;

        q.push({beginWord, 1});

        unordered_set<string> st(wordList.begin(), wordList.end());

        st.erase(beginWord);

        while(!q.empty()) {
            string word = q.front().first;
            int step = q.front().second;
            q.pop();

            if(word == endWord) return step;

            for(int i=0; i<word.size(); i++) {
                char org = word[i];
                for(auto ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if(st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word, step + 1});
                    }
                }
                word[i] = org;
            }
        }
        return 0;
    }
};

int main() {
    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";

    Solution obj;
    cout << obj.ladderLength(startWord, targetWord, wordList) << endl;
    return 0;
}

/*

Complexity Analysis

Time Complexity: O(N * L * 26), where N is the number of words in the list and L is the length of each word. For each word, we attempt to change each of its L characters to 26 possible letters.

Space Complexity: O(N * L), for the set storing all words and the queue used for BFS.

*/