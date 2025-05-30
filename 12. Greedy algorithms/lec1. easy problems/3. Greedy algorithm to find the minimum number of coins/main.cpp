// https://www.geeksforgeeks.org/problems/-minimum-number-of-coins4426/1

// https://takeuforward.org/data-structure/find-minimum-number-of-coins/

// User function Template for C++

class Solution {
  public:
    vector<int> minPartition(int N) {
        vector <int> ans;
        int coins[] =  { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        int remaining = N;
        int i = 9;
        while(remaining){
            if(coins[i]<=remaining){
                int req = remaining / coins[i];
                while(req--) ans.push_back(coins[i]);
                remaining = remaining % coins[i];
            }
            else i --;
        }
        return ans;
    }
};

/*
Time Complexity:O(V)

Space Complexity:O(1)


*/