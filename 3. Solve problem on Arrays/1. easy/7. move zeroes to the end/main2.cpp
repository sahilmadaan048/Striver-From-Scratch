
#include <bits/stdc++.h>
using namespace std;

vector<int> moveZeros(int n, vector<int> a)
{
    int j=0;
    //j points to the first index with 0
    //i points to the first non-zero elememt after this j
    while(j<n) {
        if(a[j] != 0) {
            j++;
            continue;
        }
        int i = j+1;
        while(i<n and a[i] == 0){
            i++;
        }
        if(i < n) swap(a[i], a[j]);
        j++;
    }
    return a;
}

int main()
{
    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n = 10;
    vector<int> ans = moveZeros(n, arr);
    for (auto &it : ans)
    {
        cout << it << " ";
    }
    cout << '\n';
    return 0;
}
