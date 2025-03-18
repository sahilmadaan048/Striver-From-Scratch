// https://leetcode.com/problems/palindrome-number/submissions/1577554303/
// https://takeuforward.org/data-structure/check-if-a-number-is-palindrome-or-not/

class Solution {
    public:
        bool isPalindrome(int x) {
    
                if(x<0) return false;
    
                //reverse the given integer
                int input=x;
                long int reverse=0;
                while(input!=0){
                    int ld=input%10;
                    input/=10;
                    reverse= reverse*10 +ld;
                }
    
                if(reverse==x) return true;
                else return false;     
        }
    };