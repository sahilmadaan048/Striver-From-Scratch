class Solution {
public:
    int M=1e9+7;
    int f(int i, int j, string&s, string&t, vector<vector<int>>&dp){
        if(j==0)return 1;
        if(i==0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int tk=0;
        if(s[i-1]==t[j-1] || t[j-1]=='*'){
            tk=f(i-1, j-1, s, t, dp);
        }
        int ntk=f(i-1, j, s, t, dp);
        return dp[i][j]=(tk+ntk)%M;
    }
    int countPalindromes(string s) {
        int cnt=0;
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                    char a='0'+i, b='0'+j;
                    string t;
                    t+=a;
                    t+=b;
                    t+='*';
                    t+=b;
                    t+=a;
                    vector<vector<int>>dp(s.size()+1, vector<int>(6, -1));
                    cnt=(cnt+f(s.size(), t.size(), s, t, dp)%M)%M;
            }
        }
        return cnt;
    }
};