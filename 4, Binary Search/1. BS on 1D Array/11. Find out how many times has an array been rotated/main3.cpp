#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 2, 2};
    unordered_map<int, int> freq;

    for(auto ele: arr) {
        freq[ele]++;
    }

    int count = 0;

    vector<int> temp;
    int u = 0;
    for(auto f: freq) {
        int num = f.first;
        int fr = f.second;
        temp.push_back(num);
    }

    for(int i=0; i<temp.size(); i++) {
        for(int j=i; j<temp.size(); j++) {
            int a = temp[i], b = temp[j];


            if((a  & b) > (a ^ b)) {
                if(i == j) { // if is it same element 2, 2, 2, num = 2, f = 3
                    count += (freq[a] * (freq[a] - 1))/2;
                } else {
                    count += (freq[a] * freq[b]);
                }
            }
        }
    }

    cout << count << endl;
}

// 
// 1 2 2 2 



using namespace std;

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 7, 15}; 
    unordered_map<int, int> freq;

    for (int x : arr) freq[x]++;

    long long count = 0;
    vector<int> temp;

    for (auto &[val, _] : freq)
        temp.push_back(val);

    for (int i = 0; i < temp.size(); ++i) {
        int a = temp[i];
        int fa = freq[a];

        if ((a & a) > (a ^ a)) { 
            count +=  fa * (fa - 1) / 2;
        }

        for (int j = i + 1; j < temp.size(); ++j) {
            int b = temp[j];
            int fb = freq[b];

            if ((a & b) > (a ^ b)) {
                count +=   fa * fb;
            }
        }
    }

    return 0;
}