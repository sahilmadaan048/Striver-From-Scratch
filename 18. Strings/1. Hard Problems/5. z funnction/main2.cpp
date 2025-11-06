// https://cp-algorithms.com/string/z-function.html

#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(string & s) {
    int n = s.size();
    vector<int> z(n);
    for(int i=0; i<n; i++) {
        while(i + z[i] < n and s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
    }
    return z;
}

vector<int> z_function_trivial(string & s) {
    int n = s.size();
    vector<int> z(n);

    int l = 0, r = 0;
    for(int i=1; i<n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i-l]);
        }
        while(i + z[i] < n and s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] < r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main() {
    string s = "sahilmadaansahilmadsahilmadaansahilmasasahilmadaan", t = "sahil";
    string temp = t + '$' + s;

    vector<int> ans;
    
    vector<int> z1 = z_function(temp);
    vector<int> z = z_function_trivial(temp);
    
    for(int i=0; i<z.size(); i++) {
        if(z[i] == t.size()) {
            ans.push_back(i - t.size() - 1);
        }
    }

    for(auto ele: ans) {
        cout << ele << " ";
    }
    cout << "\n";
    return 0;
}
