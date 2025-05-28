// https://takeuforward.org/plus/dsa/problems/letter-combinations-of-a-phone-number

// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

class Solution {
    unordered_map<char, string> temp = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, 
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };

    void generate(int ind, int n, string& curr, vector<string>& ans, string& digits) {
        if (ind == n) {
            ans.push_back(curr);
            return;
        }

        string s = temp[digits[ind]];
        for (int i = 0; i < s.size(); i++) {
            curr.push_back(s[i]);
            generate(ind + 1, n, curr, ans, digits);
            curr.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> ans;
        if (n == 0) return ans;

        string curr = "";
        generate(0, n, curr, ans, digits);
        return ans;
    }
};
