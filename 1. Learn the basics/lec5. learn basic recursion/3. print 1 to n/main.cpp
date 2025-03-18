// http://geeksforgeeks.org/problems/print-1-to-n-without-using-loops-1587115620/1

// https://takeuforward.org/recursion/print-1-to-n-using-recursion/

class Solution
{
    void print(int i, int n)
    {
        if (i == n)
        {
            cout << n << " ";
            return;
        }
        cout << i << " ";
        print(i + 1, n);
    }

public:
    // Complete this function
    void printNos(int n)
    {
        // Your code here(j);
        print(1, n);
    }
};
