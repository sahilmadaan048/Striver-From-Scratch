
// https://leetcode.com/problems/sum-of-subarray-minimums/description/

class Solution {
public:
    int n;
    const int MOD=1e9+7;
    typedef unsigned long long ll;
    vector<int> getNSL(vector<int>&arr){
        stack<int>st;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            if(st.empty()){
                ans[i]=-1;
            } else{
                while(!st.empty() && arr[st.top()]>arr[i]){
                    st.pop();
                }
                ans[i]=st.empty()?-1:st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> getNSR(vector<int>&arr){
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                ans[i]=n;
            } else{
                while(!st.empty() && arr[st.top()]>=arr[i]){
                    st.pop();
                }
                ans[i]=st.empty()?n:st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        n=arr.size();
        vector<int>NSL=getNSL(arr);
        vector<int>NSR=getNSR(arr);
        ll ans=0;
        for(int i=0;i<n;i++){
            ll leftSide=i-NSL[i];
            ll rightSide=NSR[i]-i;

            ll combined=leftSide*rightSide;
            ll total=combined*arr[i];

            ans=(ans+total)%MOD;
        }
        return ans;
    }
};