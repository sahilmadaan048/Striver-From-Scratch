// https://leetcode.com/problems/combination-sum-iii/

// https://takeuforward.org/plus/dsa/problems/combination-sum-iii?tab=editorial

class Solution {
    void generate(vector<vector<int>>& ans, vector<int>& curr, int start, int k, int n, int currsum) {
        if (curr.size() == k) {
            if (currsum == n) {
                ans.push_back(curr);
            }
            return;
        }

        for (int i = start; i <= 9; i++) {
            if (currsum + i > n) break;

            curr.push_back(i);
            generate(ans, curr, i + 1, k, n, currsum + i);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        generate(ans, curr, 1, k, n, 0);
        return ans;
    }
};
