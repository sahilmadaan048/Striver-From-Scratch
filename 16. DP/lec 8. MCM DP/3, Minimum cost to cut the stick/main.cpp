// https://takeuforward.org/data-structure/minimum-cost-to-cut-the-stick-dp-50/

// https://www.youtube.com/watch?v=xwomavsC86c

// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/


#include <bits/stdc++.h>
using namespace std;

int findMinimumCost(int i, int j, vector<int> &cuts) {
    if (i > j) {
        return 0;
    }

    int mini = INT_MAX;

    for (int ind = i; ind <= j; ind++) {
        int ans = cuts[j + 1] - cuts[i - 1] +
                  findMinimumCost(i, ind - 1, cuts) +
                  findMinimumCost(ind + 1, j, cuts);

        mini = min(mini, ans);
    }

    return mini;
}

int minimumCost(int n, int c, vector<int> &cuts) {
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());

    return findMinimumCost(1, c, cuts);
}

int main() {
    vector<int> cuts = {3, 5, 1, 4};
    int c = cuts.size();
    int n = 7;

    cout << "The minimum cost incurred is: " << minimumCost(n, c, cuts) << endl;

    return 0;
}

// Time Complexity: Exponential