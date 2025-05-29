class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        for(int i=0; i<n; i++) {
            for(int j=1; j<=n; j++) {
                string temp = s.substr(i, j);
                string temp2 = temp;
                reverse(temp2.begin(), temp2.end());
                if(temp == temp2 and temp.size() > ans.size()) {
                    ans = temp;
                }
            }
        }

        return ans;
    }
};