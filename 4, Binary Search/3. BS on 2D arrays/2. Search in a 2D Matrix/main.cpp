// https://www.youtube.com/watch?v=JXU4Akft7yk

// https://leetcode.com/problems/search-a-2d-matrix/

// https://takeuforward.org/data-structure/search-in-a-sorted-2d-matrix/


// https://www.youtube.com/watch?v=JXU4Akft7yk

// https://leetcode.com/problems/search-a-2d-matrix/

// https://takeuforward.org/data-structure/search-in-a-sorted-2d-matrix/


#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();

    //traverse the matrix:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == target)
                return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    searchMatrix(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}


/*

Time Complexity: O(N X M), where N = given row number, M = given column number.
Reason: In order to traverse the matrix, we are using nested loops running for n and m times respectively.

Space Complexity: O(1) as we are not using any extra space.
*/