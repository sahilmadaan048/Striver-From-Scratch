// https://leetcode.com/problems/count-good-numbers/description/

class Solution {
    public:
    const int mod = 1e9+7;
        long fastexpo(long base, long expo) {
            long result = 1;
            while(expo) {
                if(expo&1) {
                    result = (result * base) % mod;
                }
                base = (base*base) % mod;
                expo /= 2;
            }
            return result;
        }
        int countGoodNumbers(long long n) {
            // every place has 5 choices, basically we have calculate 
            long long even = (n+1)/2;
            long odd = n/2;
            long evenways = fastexpo(5, even);
            long oddways = fastexpo(4, odd);
    
            return (int)((evenways * oddways) % mod);   
        }
    };