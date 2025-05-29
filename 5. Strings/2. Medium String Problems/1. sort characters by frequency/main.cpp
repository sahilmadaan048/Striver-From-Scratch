// https://leetcode.com/problems/sort-characters-by-frequency/submissions/1647682560/


class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char, int> mp;

        for(auto ele: s) {
            mp[ele]++;
        }

        sort(s.begin(), s.end(), [&](const auto & a, const auto & b) {
            if(mp[a] == mp[b]) {
                return a < b;
            } else {
                return mp[a] > mp[b];
            }
        });

        return s;
    }
};