/*

Minimum number of platforms required for a railway
100
Hint
Given the arrival and departure times of all trains reaching a particular railway station, determine the minimum number of platforms required so that no train is kept waiting. Consider all trains arrive and depart on the same day.



In any particular instance, the same platform cannot be used for both the departure of one train and the arrival of another train, necessitating the use of different platforms in such cases.


Examples:
Input : Arrival = [0900, 0940, 0950, 1100, 1500, 1800] , Departure = [0910, 1200, 1120, 1130, 1900, 2000]



Output : 3



Explanation : The first , second , fifth number train can use the platform 1.

The third and sixth train can use the platform 2.

The fourth train will use platform 3.

So total we need 3 different platforms for the railway station so that no train is kept waiting.

Input : Arrival = [0900, 1100, 1235] , Departure = [1000, 1200, 1240]



Output : 1



Explanation : All the three trains can use the platform 1.

So we required only 1 platform.


*/


class Solution {
public:
    int findPlatform(vector<int>& Arrival, vector<int>& Departure) {
        int n = Arrival.size();
        int ans = 1; // At least one platform is needed

        for (int i = 0; i < n; i++) {
            int count = 1; // Count of overlapping trains at time i

            for (int j = i + 1; j < n; j++) {
                // Check if train i and train j overlap in time
                if ((Arrival[i] >= Arrival[j] && Arrival[i] <= Departure[j]) ||
                    (Arrival[j] >= Arrival[i] && Arrival[j] <= Departure[i])) {
                    count++;
                }
            }

            ans = max(ans, count); // Update the max platforms needed
        }

        return ans;
    }
};

/*


Time Complexity: O(n^2)  (due to two nested loops).

Space Complexity: O(1)  (no extra space used).

*/