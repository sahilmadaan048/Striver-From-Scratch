
// https://leetcode.com/problems/repeated-string-match/description/
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n1 = a.size();
        int n2 = b.size();

        int cnt = (n2 + n1 - 1) / n1;  // minimum repetitions needed to cover length of b
        string temp = "";

        // Try with cnt and cnt + 1 repetitions
        for (int i = 0; i < cnt; i++) {
            temp += a;
        }
        if (temp.find(b) != string::npos) return cnt;

        temp += a;
        if (temp.find(b) != string::npos) return cnt + 1;

        return -1;
    }
};
