// https://leetcode.com/problems/palindrome-partitioning-ii/description/

// https://takeuforward.org/data-structure/palindrome-partitioning-ii-front-partition-dp-53/

class Solution {
    bool isPalindrome(int i, int j, string &s) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int minPartitions(int i, int n, string & s) {
        if(i == n) return 0;
        int minCost = INT_MAX;

        for(int j=i; j<n; j++) {
            if(isPalindrome(i, j, s)) {
                int cost = 1 + minPartitions(j+1, n, s);
                minCost = min(minCost, cost);
            }
        }
        return minCost;
    }
public:
    int minCut(string s) {
        int n = s.size();

        int partitions = minPartitions(0, n, s);
        // count partitions and minus 1 for nmber of vuts
        return partitions - 1;
    }   
};

/*

Time Complexity: Exponential

*/