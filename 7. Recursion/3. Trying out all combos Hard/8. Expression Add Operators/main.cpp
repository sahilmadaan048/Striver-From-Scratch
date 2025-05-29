// https://leetcode.com/problems/expression-add-operators/submissions/1647599225/

class Solution {
    void generate(int ind, string& path, long currVal, long prevNum, vector<string>& ans, string& num, int target) {
        if (ind == num.size()) {
            if (currVal == target) {
                ans.push_back(path);
            }
            return;
        }

        for (int i = ind; i < num.size(); ++i) {
            // Avoid numbers with leading zeros
            if (i != ind && num[ind] == '0') break;

            string currStr = num.substr(ind, i - ind + 1);
            long currNum = stol(currStr);

            int pathLen = path.size();

            if (ind == 0) {
                // First number, no operator
                path += currStr;
                generate(i + 1, path, currNum, currNum, ans, num, target);
                path.resize(pathLen);
            } else {
                // +
                path += "+" + currStr;
                generate(i + 1, path, currVal + currNum, currNum, ans, num, target);
                path.resize(pathLen);

                // -
                path += "-" + currStr;
                generate(i + 1, path, currVal - currNum, -currNum, ans, num, target);
                path.resize(pathLen);

                // *
                path += "*" + currStr;
                generate(i + 1, path, currVal - prevNum + prevNum * currNum, prevNum * currNum, ans, num, target);
                path.resize(pathLen);
            }
        }
    }

public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string path = "";
        generate(0, path, 0, 0, ans, num, target);
        return ans;
    }
};
