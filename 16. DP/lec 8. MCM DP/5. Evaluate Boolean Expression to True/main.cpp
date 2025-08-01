// https://takeuforward.org/data-structure/evaluate-boolean-expression-to-true-partition-dp-dp-52/

// https://leetcode.com/problems/parsing-a-boolean-expression/



#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1000000007;

int f(int i, int j, int isTrue, string &exp) {
    // Base case 1: If i > j, it's an invalid expression, return 0.
    if (i > j) return 0;
    
    // Base case 2: If i and j are the same, evaluate the single character.
    if (i == j) {
        if (isTrue == 1) return exp[i] == 'T' ? 1 : 0;
        else return exp[i] == 'F' ? 1 : 0;
    }
    
    ll ways = 0;
    
    // Iterate through the expression.
    for (int ind = i + 1; ind <= j - 1; ind += 2) {
        ll lT = f(i, ind - 1, 1, exp);  // Number of ways to make the left expression true.
        ll lF = f(i, ind - 1, 0, exp);  // Number of ways to make the left expression false.
        ll rT = f(ind + 1, j, 1, exp);  // Number of ways to make the right expression true.
        ll rF = f(ind + 1, j, 0, exp);  // Number of ways to make the right expression false.

        // Check the operator at the current index and update ways accordingly.
        if (exp[ind] == '&') {
            if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
        }
        else if (exp[ind] == '|') {
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rF) % mod) % mod;
        }
        else {  // XOR operator
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
            else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
        }
    }
    return ways;
}

int evaluateExp(string &exp) {
    int n = exp.size();
    return f(0, n - 1, 1, exp);  // Start evaluation with isTrue set to true.
}

int main() {
    string exp = "F|T^F";
    int ways = evaluateExp(exp);
    cout << "The total number of ways: " << ways << "\n";
    return 0;
}


/*
Time Complexity: Exponential
*/