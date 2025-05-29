#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s) {
    int n = s.size();
    vector<int> pi(n, 0);

    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }

    return pi; // You must return pi
}

int main() {
    string s = "abcabcd";
    vector<int> res = prefix_function(s);

    for (auto i : res) {
        cout << i << " ";
    }
    cout << "\n";

    // KMP search example
    string s2 = "na";
    vector<int> res2 = prefix_function(s2); // prefix array for pattern s2

    string t = "apnacollege";
    int i = 0, j = 0;
    int pos = -1;

    while (i < (int)t.size()) {
        if (t[i] == s2[j]) {
            i++;
            j++;
        } else {
            if (j != 0) {
                j = res2[j - 1]; // use prefix array computed for s2
            } else {
                i++;
            }
        }
        if (j == (int)s2.size()) {
            pos = i - (int)s2.size();
            break;
        }
    }

    cout << "Pattern found at index: " << pos << "\n";

    return 0;
}
