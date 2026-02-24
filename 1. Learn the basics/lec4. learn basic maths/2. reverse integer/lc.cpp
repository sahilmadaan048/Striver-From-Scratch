class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        int n = s.size();
        bool flag = false;
        int i = 0;
        if(x < 0) {
            flag = true;
            i++;
        }
        while(i < n and s[i] == '0') {
            i++;
        }   

        string ans = "";
        int j = n-1;
        while(j >= i and s[j] == '0') {
            j--;
        }
        while(j >= i) {
            ans += s[j];
            j--;
        }
        if(ans.size() == 0) return 0;
        long long temp = stoll(ans);
        if(flag) temp = -temp;
        if(temp  > INT_MAX or temp  < INT_MIN) return 0;
        return temp;
    }
};

// TC - O(n)
// SC - O(n)