// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/description/



// https://takeuforward.org/plus/dsa/problems/longest-substring-with-at-most-k-distinct-characters?tab=editorial


class Solution {
public:
    int kDistinctChar(string& s, int k) {
        //your code goes here
        int n = s.size();

        int i = 0 ;
        int j = 0 ;
        int ans = 0;

        unordered_map<char, int> mpp;

        while(j < n) {
            mpp[s[j]]++;

            while(mpp.size() > k) {
                mpp[s[i]]--;
                if(mpp[s[i]] == 0) mpp.erase(s[i]);
                i++;
            }   

            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};