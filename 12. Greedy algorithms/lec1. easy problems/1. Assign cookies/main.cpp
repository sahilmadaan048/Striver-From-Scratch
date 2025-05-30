// https://leetcode.com/problems/assign-cookies/description/

// https://takeuforward.org/Greedy/assign-cookies


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());

        int n = g.size();
        int m = s.size();

        int i = 0, j = 0;
        int cnt = 0;

        while(i < n && j < m) {
            if(g[i] <= s[j]) {
                cnt++;
                i++;
            }
            j++;
        }

        return cnt;
    }
};


/*
Time Complexity: O(N logN + M logM + M) where N is the length of the greedy array, M is the length of the cookies array. To sort the greedy and cookies array, the complexity is O(N logN) and O(M logM).

After sorting, we iterate over the arrays at most M times as M is the total number of cookies.
Since each child and each cookie is considered at most once, the time complexity of this part is linear in terms of the size of the cookie array, which is O(M).
Space Complexity: O(1) as the algorithm uses only a constant amount of extra space regardless of the size of the input array. It does not require any additional data structures that scale with the input size.

*/