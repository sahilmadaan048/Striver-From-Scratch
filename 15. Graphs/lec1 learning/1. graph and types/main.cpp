// https://takeuforward.org/graph/introduction-to-graph/

// https://www.geeksforgeeks.org/problems/graph-and-vertices/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=graph-and-vertices

class Solution {
    public:
      long long count(int n) {
          if(n<=2){
              return n;
          }
          long long edges = (n*(n-1))/2;
          long long ans = pow(2,edges);
          
          return ans;
      }
  };