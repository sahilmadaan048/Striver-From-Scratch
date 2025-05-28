// https://leetcode.com/problems/palindrome-partitioning/description/

// https://takeuforward.org/data-structure/palindrome-partitioning/

// https://takeuforward.org/plus/dsa/problems/palindrome-partitioning

class Solution {
    bool checkPalindrome(string & s) {
        int i = 0;
        int j = s.size() - 1;
        while(i < j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
    
    void generate(int ind, int n, vector<string>& curr, vector<vector<string>>& ans, string& s) {
        if(ind == n) {
            ans.push_back(curr);
            return;
        }

        //whats next
        for(int i=ind; i<n; i++) {
            string temp = s.substr(ind, i - ind + 1);
            if(checkPalindrome(temp)) {
                curr.push_back(temp);
                generate(i + 1, n, curr, ans, s);
                curr.pop_back();
            }
        }        
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> ans;
        vector<string> curr = {};
        generate(0, n, curr, ans, s);
        return ans;
    }
};