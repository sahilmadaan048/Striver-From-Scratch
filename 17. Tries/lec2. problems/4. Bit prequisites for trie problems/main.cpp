// https://www.geeksforgeeks.org/problems/bits-basic-operations/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bits-basic-operations


// https://www.youtube.com/watch?v=5iyuU4hQFrw&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp&index=6

class Solution {
  public:
    int XOR(int n, int m) {
        // code here
        return n^m;
    }
    int check(int a, int b) {
        // code here
        return ((b>>(a-1))&1);
    }
    int setBit(int c, int d) {
        // code here
        int ans = 1<<c;
        return d|ans;
    }
};
