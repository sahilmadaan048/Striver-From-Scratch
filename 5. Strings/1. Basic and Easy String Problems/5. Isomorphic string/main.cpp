// https://leetcode.com/problems/isomorphic-strings/description/''

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map1;
        unordered_map<char, char> map2;
        int n = s.size();
        string S, T;

        for(int i = 0; i<n; i++){
            map1[s[i]] = t[i];
            map2[t[i]] = s[i];
        }

        for(int i = 0; i<n; i++){
            S.push_back(map1[s[i]]);
            T.push_back(map2[t[i]]);
        }

        if(s == T and t == S)return true;
        return false;
    }
};