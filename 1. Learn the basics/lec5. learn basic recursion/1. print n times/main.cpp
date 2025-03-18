// https://takeuforward.org/recursion/introduction-to-recursion-understand-recursion-by-printing-something-n-times/

// https://www.geeksforgeeks.org/problems/print-1-to-n-without-using-loops-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=print-1-to-n-without-using-loops

#include <bits/stdc++.h>
using namespace std;
int cnt = 0;

void print()
{

    // Base Condition.
    if (cnt == 3)
        return;
    cout << cnt << endl;

    // Count Incremented
    cnt++;
    print();
}

int main()
{
    print();
    return 0;
}