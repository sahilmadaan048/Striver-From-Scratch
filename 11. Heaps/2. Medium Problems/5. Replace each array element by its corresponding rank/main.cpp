// https://www.geeksforgeeks.org/problems/replace-elements-by-its-rank-in-the-array/1

// https://takeuforward.org/data-structure/replace-elements-by-its-rank-in-the-array/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 6;

    int arr[n] = {20, 15, 25, 2, 98, 6};

    for(int i=0; i<n; i++) {
        set<int> st;

        for(int j=0; j<n; j++)  {
            if(arr[j] < arr[i]) {
                st.insert(arr[j]);
            }
        }
        cout  << st.size() + 1 << " ";
    }
}