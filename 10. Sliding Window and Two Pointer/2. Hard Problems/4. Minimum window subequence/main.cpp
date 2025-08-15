// https://leetcode.com/problems/minimum-window-subsequence/description/

// https://www.geeksforgeeks.org/dsa/minimum-window-subsequence/



/**
 * 
 * [Naive Approach] Brute Force with Substring and Subsequence Check - O(n^3) Time and O(1) Space
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(string& sub, string &s2) {
    int i=0; 
    int  j = 0;

    while(i<sub.size() && s2.size()) {
        if(sub[i] == s2[j]) j++;
        i++;
    }
    return j == s2.size();
}

string minWindow(string& s1, string& s2) {
    int n = s1.size();
    string ans = "";
    int minLen = INT_MAX;


    for(int start = 0; start <n; start++) {
        for(int end = start; end < n; end++) {
            string sub1 = s1.substr(start,  end, end - start + 1);

            if(isSubsequence(sub, s2)) {
                if(sub.size() < minLen) {
                    minLen = sub.size));
                    ans = sub;
                }
            }
            break;
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