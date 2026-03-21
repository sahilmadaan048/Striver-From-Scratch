#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());

        queue<vector<string>> q;

        q.push({beginWord});

        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;

        vector<vector<string>> ans;

        while(!q.empty()) { 
            vector<string> vec = q.front();
            q.pop();

            if(vec.size() > level) {
                level++;
                for(auto it: usedOnLevel) {
                    st.erase(it);
                }
            }

            string word = vec.back();

            if(word == endWord){
                if(ans.size() == 0) {
                    ans.push_back(vec);
                }
                else if (ans[0].size() == vec.size()){
                    ans.push_back(vec);
                }
            }

            for(int i=0; i<word.size(); i++) {
                char original = word[i];
                for(auto ch='a'; ch<='z'; ch++) {
                    word[i] = ch;
                    if(st.count(word)) {
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }   
        return ans;
    }
};

// A comparator function to sort the answer.
bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for (string i : a)
        x += i;
    for (string i : b)
        y += i;

    return x < y;
}

int main()
{

    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";
    Solution obj;
    vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);

    // If no transformation sequence is possible.
    if (ans.size() == 0)
        cout << -1 << endl;
    else
    {
        sort(ans.begin(), ans.end(), comp);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}

/*


Complexity Analysis

Time Complexity: O(N × L × 26 + S × L) → dominated by generating all transformations (N = words, L = word length, S = number of shortest sequences).

Space Complexity: O(N × L + S × L) → for queue storing paths, set for unused words, and final sequences.

*/