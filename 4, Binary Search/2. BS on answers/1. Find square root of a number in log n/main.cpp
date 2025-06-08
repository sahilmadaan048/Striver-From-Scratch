// https://takeuforward.org/binary-search/finding-sqrt-of-a-number-using-binary-search/




#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int n) {
    int ans = 0;
    //linear search on the answer space:
    for (long long i = 1; i <= n; i++) {
        long long val = i * i;
        if (val <= n * 1ll) {
            ans = i;
        } else {
            break;
        }
    }
    return ans;
}

int main()
{
    int n = 28;
    int ans = floorSqrt(n);
    cout << "The floor of square root of " << n
         << " is: " << ans << "\n";
    return 0;
}

/*

Time Complexity: O(N), N = the given number.
Reason: Since we are using linear search, we traverse the entire answer space.

Space Complexity: O(1) as we are not using any extra space.


*/