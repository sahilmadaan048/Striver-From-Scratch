// https://leetcode.com/problems/count-and-say/description/

class Solution {
    void recCal(int cnt, int n, string& ans) {
        if(cnt == n - 1) return;

        string temp = "";
        int i = 0;
        while(i < ans.size()) {
            char curr = ans[i];
            int count = 0;
            while(i < ans.size() && ans[i] == curr) {
                count++;
                i++;
            }
            temp += to_string(count) + curr;
        }
        ans = temp;
        recCal(cnt + 1, n, ans);
    }
public:
    string countAndSay(int n) {
        string ans = "1";
        recCal(0, n, ans);
        return ans;
    }
};
