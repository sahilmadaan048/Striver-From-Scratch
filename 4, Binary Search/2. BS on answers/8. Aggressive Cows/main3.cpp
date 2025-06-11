// User function Template for C++
// https://www.geeksforgeeks.org/problems/aggressive-cows/1


class Solution {
  public:

bool isPossible(vector<int> &stalls,int k,int min_dist){
        int cow=1;
        int last_pos=stalls[0];
        int n=stalls.size();
        for(int i=1;i<n;i++){
            if(stalls[i]-last_pos >=min_dist){
                cow++;
                last_pos=stalls[i];
            }
            
            if(cow==k){
                return true;
            }
        }
        
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        int n=stalls.size();
        sort(stalls.begin(),stalls.end());
        int s=1; // smallest possible distance
        int e=stalls[n-1]-stalls[0]; // maximum distance
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s) /2;
            if(isPossible(stalls,k,mid)){
                ans=mid;
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
        
        return ans;
    }


};