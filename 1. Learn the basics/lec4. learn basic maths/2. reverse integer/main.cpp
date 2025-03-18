// https://leetcode.com/problems/reverse-integer/submissions/1577552884/
// https://takeuforward.org/strivers-a2z-dsa-course/strivers-a2z-dsa-course-sheet-2/
class Solution
{
public:
    int reverse(int x)
    {
        long long ans = 0;
        while (x)
        {
            int d = x % 10;
            x /= 10;
            if (ans > INT_MAX / 10 || (ans >= INT_MAX / 10 and d > 7))
                return 0;
            if (ans < INT_MIN / 10 || (ans <= INT_MIN / 10 and d > 7))
                return 0;
            ans = (ans * 10) + d;
        }
        return (int)ans;
    }
};