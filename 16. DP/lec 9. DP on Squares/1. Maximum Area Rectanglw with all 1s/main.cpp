// https://takeuforward.org/data-structure/maximum-rectangle-area-with-all-1s-dp-on-rectangles-dp-55/

// https://leetcode.com/problems/maximal-rectangle/description/

class Solution {
    int histogramArea(vector<int>& histo) {
        stack<int> st;
        int n = histo.size();
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
                int height = histo[st.top()];
                st.pop();

                int width;
                if (st.empty()) width = i;
                else width = i - st.top() - 1;

                int area = height * width;
                maxArea = max(area, maxArea);
            }
            st.push(i);
        }

        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();
        int maxArea = 0;
        vector<int> height(m, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }

            int area = histogramArea(height);
            maxArea = max(area, maxArea);
        }

        return maxArea;
    }
};


/*

Time Complexity: O(N * (M+M)), where N = total no. of rows and M = total no. of columns.
Reason: O(N) for running a loop to check all rows. Now, inside that loop, O(M) is for visiting all the columns, and another O(M) is for the function we are using. The function takes linear time complexity. Here, the size of the height array is M, so it will take O(M).

Space Complexity: O(M), where M = total no. of columns.
Reason: We are using a height array and a stack of size M.
*/