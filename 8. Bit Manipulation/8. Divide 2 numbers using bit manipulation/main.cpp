// https://leetcode.com/problems/divide-two-integers/description/

    
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Convert to long long to prevent overflow
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long ans = 0;

        while (a >= b) {
            int q = 0;
            // Find the largest power of 2 such that (b << q) <= a
            while (a >= (b << (q + 1))) {
                q++;
            }
            ans += (1LL << q);
            a -= (b << q);
        }

        // Apply sign
        bool isPositive = (dividend < 0) == (divisor < 0);
        return isPositive ? ans : -ans;
    }
};
