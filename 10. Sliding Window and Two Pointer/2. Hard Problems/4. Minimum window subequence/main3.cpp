/***
 * 
 * [Expected Approach] Preprocessing with Next Occurrence Table - O(n × m) Time and O(n) Time
 * 
 * 
 * 
 */


/***
 * 
 * EVIL APPROACH
 * SINCE IT DOES NOT COME INTUITIVELY
 */


 #include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <bits/stdc++.h>
using namespace std;

string minWindow(string &s1, string &s2) {
    int n = s1.size();
    int m = s2.size();

    // nextPos[i][ch] : next occurrence of character
    // ch after index i in s1
    vector<vector<int>> nextPos(n + 2, vector<int>(26, -1));

    // initialize last row with -1 (no occurrence beyond end)
    for (int c = 0; c < 26; c++) {
        nextPos[n][c] = -1;
    }

    // fill table by going backwards through s1
    for (int i = n - 1; i >= 0; i--) {
        for (int c = 0; c < 26; c++) {
            nextPos[i][c] = nextPos[i + 1][c];
        }
        nextPos[i][s1[i] - 'a'] = i;
    }

    string ans = "";
    int minLen = INT_MAX;

    // try starting at each position in s1
    for (int start = 0; start < n; start++) {
        if (s1[start] != s2[0]) continue;

        int idx = start;
        bool ok = true;

        // match s2 by jumping through nextPos
        for (int j = 0; j < m; j++) {
            if (idx == -1) {
                ok = false;
                break;
            }
            idx = nextPos[idx][s2[j] - 'a'];
            if (idx == -1) {
                ok = false;
                break;
            }   
            // move to next index for next char
            idx++; 
        }

        if (ok) {
            int endIdx = idx - 1;
            int len = endIdx - start + 1;
            if (len < minLen) {
                minLen = len;
                ans = s1.substr(start, len);
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


/***
 * 
 * EVIL APPROACH
 * 
 */