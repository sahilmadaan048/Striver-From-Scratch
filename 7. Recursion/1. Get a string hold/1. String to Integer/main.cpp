// https://leetcode.com/problems/string-to-integer-atoi/description/

class Solution {
    public:
        const long long MAX = 9223372036854775807;  // max value for long long
        const long long MIN = -9223372036854775808; // min value for long long
        
        void recCal(int start, int end, long long &ans, string &s, bool &overflow) {
            if(start > end || !isdigit(s[start])) return;
            
            int digit = s[start] - '0';
            
            // Check for overflow before multiplying
            if (ans > MAX / 10 || (ans == MAX / 10 && digit > MAX % 10)) {
                overflow = true;
                return;
            }
            
            ans = ans * 10 + digit;
            recCal(start + 1, end, ans, s, overflow);
        }
    
        int myAtoi(string s) {
            int n = s.size();
            int start = 0;
            while(start < n && s[start] == ' ') start++; // skip leading spaces
    
            bool negative = false;
            if(start < n && (s[start] == '-' || s[start] == '+')) {
                negative = (s[start] == '-');
                start++;
            }
    
            long long ans = 0;
            bool overflow = false;
            recCal(start, n - 1, ans, s, overflow);
    
            if (overflow) {
                return negative ? INT_MIN : INT_MAX;
            }
    
            ans = negative ? -ans : ans;
    
            if(ans > INT_MAX) return INT_MAX;
            if(ans < INT_MIN) return INT_MIN;
    
            return ans;
        }
    };
    