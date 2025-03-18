// https://leetcode.com/problems/armstrong-number/description/

// https://takeuforward.org/maths/check-if-a-number-is-armstrong-number-or-not/

// https://www.naukri.com/code360/problems/check-armstrong_589?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf


bool checkArmstrong(int n) {
    int digits = (int)(log10(n) + 1);
    
    int temp = n, sum = 0;
    while (temp) {
        int digit = temp % 10;
        int power = 1;
        for (int i = 0; i < digits; i++) {
            power *= digit;  
        }
        sum += power;
        temp /= 10;  
    }

    return sum == n;
}
