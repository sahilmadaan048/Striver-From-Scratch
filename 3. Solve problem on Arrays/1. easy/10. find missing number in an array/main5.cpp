class Solution {
public:
    int missingNumber(vector<int>& a) {
        int x = 0;
        int n = a.size();
        for(int i=0; i<=n; i++) x ^= i;
        for(int i=0; i<n; i++) x ^= a[i];

        return x;
    }
};