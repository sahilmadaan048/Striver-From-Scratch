/***
 * 
 * [Better Approach] Two-Pointer Forward Scan with Backtracking - O(n^2) Time and O(1) Spacew
 * 
 */

#include <iostream>
#include <climits>
#include <string>
using namespace std;

string minWindow(string &s1, string &s2) {
    int n = s1.size();
    int m = s2.size();
    string ans = "";
    int minLen = INT_MAX;

    for (int i = 0; i < n; i++) {
        // find starting point where s1[i] matches s2[0]
        if (s1[i] == s2[0]) {
            int p1 = i, p2 = 0;

            // move forward until s2 is matched
            while (p1 < n && p2 < m) {
                if (s1[p1] == s2[p2]) p2++;
                p1++;
            }

            // if we matched all characters of s2
            if (p2 == m) {
                // last matched index
                int end = p1 - 1; 
                p2 = m - 1;

                // backtrack to find minimal starting index
                while (end >= i) {
                    if (s1[end] == s2[p2]) p2--;
                    if (p2 < 0) break;
                    end--;
                }

                int start = end;
                int len = p1 - start;
                if (len < minLen) {
                    minLen = len;
                    ans = s1.substr(start, len);
                }
            }
        }
    }
    return ans;
}

int main() {
    string s1 = "abcdebdde";
    string s2 = "bde";
    cout << minWindow(s1, s2) << endl;
    return 0;
}