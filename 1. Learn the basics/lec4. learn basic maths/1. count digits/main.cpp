// https://www.apnacollege.in/path-player?courseid=sigma-batch-development&unit=664499ddc5a98a45a60c9fcbUnit

// https://www.geeksforgeeks.org/problems/count-digits5716/1

class Solution {
    public:
      // Function to count the number of digits in n that evenly divide n
      int evenlyDivides(int n) {
          int cnt = 0;
          int temp = n;
          while (temp > 0) {    
              int d = temp % 10;
              if (d != 0 && n % d == 0) cnt++; 
              temp /= 10;
          }
          return cnt;
      }
  };