// https://leetcode.com/problems/spiral-matrix/description/

// https://takeuforward.org/data-structure/spiral-traversal-of-matrix/



class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int rs = 0, cs = 0;        // row start, column start
        int re = m - 1, ce = n - 1; // row end, column end

        vector<int> ans;

        while(rs <= re && cs <= ce) {
            // left to right
            for(int i = cs; i <= ce; i++)
                ans.push_back(matrix[rs][i]);
            rs++;

            // top to bottom
            for(int i = rs; i <= re; i++)
                ans.push_back(matrix[i][ce]);
            ce--;

            // right to left
            if(rs <= re) {
                for(int i = ce; i >= cs; i--)
                    ans.push_back(matrix[re][i]);
                re--;
            }

            // bottom to top
            if(cs <= ce) {
                for(int i = re; i >= rs; i--)
                    ans.push_back(matrix[i][cs]);
                cs++;
            }
        }

        return ans;
    }
};


/*

Time Complexity: O(m x n) { Since all the elements are being traversed once and there are total n x m elements ( m elements in each row and total n rows) so the time complexity will be O(n x m)}.

Space Complexity: O(n) { Extra Space used for storing traversal in the ans array }.




*/