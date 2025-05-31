// https://takeuforward.org/data-structure/job-sequencing-problem/

// https://takeuforward.org/plus/dsa/problems/job-sequencing-problem?tab=editorial

// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1/

/*

Given an 2D array Jobs of size Nx3, where Jobs[i][0] represents JobID , Jobs[i][1] represents Deadline , Jobs[i][2] represents Profit associated with that job. Each Job takes 1 unit of time to complete and only one job can be scheduled at a time.



The profit associated with a job is earned only if it is completed by its deadline. Find the number of jobs and maximum profit.


Examples:
Input : Jobs = [ [1, 4, 20] , [2, 1, 10] , [3, 1, 40] , [4, 1, 30] ]

Output : 2 60

Explanation : Job with JobID 3 can be performed at time t=1 giving a profit of 40.

Job with JobID 1 can be performed at time t=2 giving a profit of 20.

No more jobs can be scheduled, So total Profit = 40 + 20 => 60.

Total number of jobs completed are two, JobID 1, JobID 3.

So answer is 2 60.

Input : Jobs = [ [1, 2, 100] , [2, 1, 19] , [3, 2, 27] , [4, 1, 25] , [5, 1, 15] ]

Output : 2 127

Explanation : Job with JobID 1 can be performed at time time t=1 giving a profit of 100.

Job with JobID 3 can be performed at time t=2 giving a profit of 27.

No more jobs can be scheduled, So total Profit = 100 + 27 => 127.

Total number of jobs completed are two, JobID 1, JobID 3.

So answer is 2 127. 


*/



#include<bits/stdc++.h>

using namespace std;
// A structure to represent a job 
struct Job {
   int id; // Job Id 
   int dead; // Deadline of job 
   int profit; // Profit if job is over before or on deadline 
};
class Solution {
   public:
      bool static comparison(Job a, Job b) {
         return (a.profit > b.profit);
      }
   //Function to find the maximum profit and the number of jobs done
   pair < int, int > JobScheduling(Job arr[], int n) {

      sort(arr, arr + n, comparison);
      int maxi = arr[0].dead;
      for (int i = 1; i < n; i++) {
         maxi = max(maxi, arr[i].dead);
      }

      int slot[maxi + 1];

      for (int i = 0; i <= maxi; i++)
         slot[i] = -1;

      int countJobs = 0, jobProfit = 0;

      for (int i = 0; i < n; i++) {
         for (int j = arr[i].dead; j > 0; j--) {
            if (slot[j] == -1) {
               slot[j] = i;
               countJobs++;
               jobProfit += arr[i].profit;
               break;
            }
         }
      }

      return make_pair(countJobs, jobProfit);
    }
};

int main() {
   int n = 4;
   Job arr[n] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};

   Solution ob;
   //function call
   pair < int, int > ans = ob.JobScheduling(arr, n);
   cout << ans.first << " " << ans.second << endl;

   return 0;
} 

