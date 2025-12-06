#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int func(int m, int n){
        vector<int> prev(n, 0);

        for (int i = 0; i < m; i++) {
            vector<int> temp(n, 0);

            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    temp[j] = 1;
                    continue;
                }

            int up = 0;
            int left = 0;

            if (i > 0)
                up = prev[j];

            if (j > 0)
                left = temp[j - 1];

            temp[j] = up + left;
        }

        prev = temp;
    }

    return prev[n - 1];
}
public:
    int uniquePaths(int m, int n) {
        return func(m, n);
    }
};
int main() {
    int m = 3;
    int n = 2;
    Solution sol;
    cout << "Number of ways: " << sol.uniquePaths(m, n) << endl;

    return 0;
}

/*
me Complexity: O(m * n), where m is the number of rows and n is the number of columns in the grid. This is because we are iterating through each cell in the grid once.

Space Complexity: O(n), as we are using two arrays of size n to store the current and previous rows. This is an optimization from the previous approaches that used a 2D array.

*/