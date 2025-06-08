


#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int n) {
    int ans = sqrt(n);
    return ans;
}

int main()
{
    int n = 28;
    int ans = floorSqrt(n);
    cout << "The floor of square root of " << n
         << " is: " << ans;
    return 0;
}

/*

Time Complexity: O(logN), N = size of the given array.
Reason: We are basically using the Binary Search algorithm.

Space Complexity: O(1) as we are not using any extra space.


*/