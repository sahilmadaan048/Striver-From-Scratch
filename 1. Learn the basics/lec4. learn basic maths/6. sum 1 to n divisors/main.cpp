// https://www.geeksforgeeks.org/problems/sum-of-all-divisors-from-1-to-n4738/1

// https://takeuforward.org/data-structure/print-all-divisors-of-a-given-number/

class Solution
{
public:
    int sumOfDivisors(int n)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += (n / i) * i; // Each i contributes to its multiples
        }
        return sum;
    }
};

//   for each i calculate the number of times its gonna contribute to the total __STDCPP_DEFAULT_NEW_ALIGNMENT__
//   whcih is n/i and i is its contribution