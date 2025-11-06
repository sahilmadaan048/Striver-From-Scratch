// https://leetcode.com/problems/climbing-stairs/description/

// https://takeuforward.org/data-structure/dynamic-programming-climbing-stairs/

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) {
            return n;
        }
        int prev = 1;
        int prev2 = 1;
        int curr;
        for(int i=2; i<=n; i++) {
            curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};