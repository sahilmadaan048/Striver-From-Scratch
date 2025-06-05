// https://leetcode.com/problems/pascals-triangle/description/

// https://takeuforward.org/data-structure/program-to-generate-pascals-triangle/

class Solution {
public:
    int ncr(int n, int r) {
        long long res = 1;

        // calculating nCr:
        for (int i = 0; i < r; i++) {
            res = res * (n - i);
            res = res / (i + 1);
        }
        return res;
    }

    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            vector<int> row(i + 1);
            for (int j = 0; j <= i; j++) {
                row[j] = ncr(i, j);
            }
            ans.push_back(row);
        }
        return ans;
    }
};
