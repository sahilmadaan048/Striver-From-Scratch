// https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1


class Solution {
  public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        
     
        vector<pair<int,int>> meetings;
        
        for(int i = 0; i < n; i++) {
            meetings.push_back({end[i], start[i]});
        }
        
        sort(meetings.begin(), meetings.end());
        
        int cnt = 1;
        int last_end = meetings[0].first;
        
        for(int i = 1; i < n; i++) {
            if(meetings[i].second > last_end) {
                cnt++;
                last_end = meetings[i].first;
            }
        }
        
        return cnt;
    }
};


// Time complexity => O(NlogN) + O(N) , for sorting the entire meetings array and storing them as pairs of  {end[i], start[i]}
// Spce Complexity => O(N) => additional space used to stire tuple of start time end time, and index