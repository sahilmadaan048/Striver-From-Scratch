// https://takeuforward.org/data-structure/fractional-knapsack-problem-greedy-approach

#include <bits/stdc++.h>
using namespace std;

// struct to represent an itm with value and weifght
struct Item {
    int value;
    int weight;
};

class Solution {
public:
    bool static comp(Item a, Item b) {
        double r1 = (double) a.value / (double) a.weight;
        double r2 = (double) b.value / (double) b.weight;
        return r1 > r2;  // Return true if the ratio of item a is greater than item b
    }

    double fractionalKnapsack(int W, Item arr[], int n) {
        sort(arr, arr + n, comp);

        int curWeight = 0;  // Current weight of knapsack
        double finalvalue = 0.0;  // Final value we can achieve

        for (int i = 0; i < n; i++) {

            if (curWeight + arr[i].weight <= W) {
                curWeight += arr[i].weight;
                finalvalue += arr[i].value;  // Add the full value of the item
            } else {
                int remain = W - curWeight;
                finalvalue += (arr[i].value / (double) arr[i].weight) * (double) remain;
                break;  // 
            }
        }

        return finalvalue;  
    }
};

int main() {
    int n = 3, weight = 50;  // Number of items and capacity of knapsack
    Item arr[n] = { {100,20},{60,10},{120,30} };
    Solution obj;

    double ans = obj.fractionalKnapsack(weight, arr, n);
    
    cout << "The maximum value is " << setprecision(2) << fixed << ans;
    return 0;
}

/*
Time Complexity: O(n log n + n). O(n log n) to sort the items and O(n) to iterate through all the items for calculating the answer.

Space Complexity: O(1), no additional data structure has been used.

*/