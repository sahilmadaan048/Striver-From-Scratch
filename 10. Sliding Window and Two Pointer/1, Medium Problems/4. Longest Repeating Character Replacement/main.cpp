// https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        // we can that operation atmost k times
        unordered_map<char, int> mpp;

        int i = 0;
        int j = 0;
        int ans = 0;
        int maxi = 0;
        while(j < n ) {
            char ch = s[j];
            mpp[ch]++;
            maxi = max(maxi, mpp[ch]);

            // if  nimber of replacements > k shrink the window
            // feom tje beginning

            // shringking consdidoton
            while((j - i + 1) - maxi > k) {
                mpp[s[i]]--;
                i++;
            }
            ans = max(ans, j -  i +1);
            j++;
        }   

        return ans;
    }
};