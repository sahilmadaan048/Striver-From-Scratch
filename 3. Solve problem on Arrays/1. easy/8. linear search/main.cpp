// https://takeuforward.org/data-structure/linear-search-in-c/

// https://www.geeksforgeeks.org/problems/who-will-win-1587115621/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=who-will-win

class Solution {
    public:
      // Function to find element in sorted array
      // arr: input array
      // k: element to be searched
      bool searchInSorted(vector<int>& arr, int k) {
  
          // Your code here
          int n = arr.size();
          int lo = 0 ;
          int hi = n-1;
          
          while(lo <= hi) {
              int mid = lo + (hi-lo)/2;
              if(arr[mid] == k) {
                  return true;
              }else if(arr[mid] < k) {
                  lo = mid+1;
              }else{
                  hi = mid-1;
              }
          }
          return false;
      }
  };