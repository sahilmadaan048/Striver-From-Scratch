// https://leetcode.com/problems/powx-n/

class Solution {
    public:
        double myPow(double x, int n) {
            double result = 1;
            long long abs_n = n; 
            if (n < 0) {
                abs_n = -abs_n;
                x = 1 / x;  // If n is negative, invert the base
            }
    
            while (abs_n) {
                if (abs_n % 2 == 1) {  // If n is odd
                    result *= x;
                }
                x *= x;  // Square the base
                abs_n /= 2;  // Halve the exponent
            }
            return result;
        }
    };
    