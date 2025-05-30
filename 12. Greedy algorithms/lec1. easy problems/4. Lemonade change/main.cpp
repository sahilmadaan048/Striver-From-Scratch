// https://takeuforward.org/Greedy/lemonade-change

// https://leetcode.com/problems/lemonade-change/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int fives = 0;
        int tens = 0;

        bool flag = true;

        for(int i=0; i<n; i++) {
            if(bills[i] == 5) {
                fives++;
            } else if(bills[i] == 10) {
                if(fives == 0) return false;
                fives--;
                tens++;
            } else if(bills[i] == 20) {
                if(tens > 0 and fives > 0) {
                    tens--;
                    fives--;
                } else if(tens == 0 and fives > 2) {
                    fives -= 3;
                }
                else {
                    flag = false;
                    break;
                }
            }
        }

        return flag;
    }
};


/*


ime Complexity: O(N) where N is the number of people in queue/ bills we will deal with. We iterate through each customer’s bills exactly once. The loop runs for N iterations and at each iteration the operations performed are constant time.

Space Complexity: O(1) as the algorithm uses only a constant amount of extra space regardless of the size of the input array. It does not require any additional data structures that scale with the input size.

*/