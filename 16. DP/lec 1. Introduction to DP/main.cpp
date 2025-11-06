// https://takeuforward.org/data-structure/dynamic-programming-introduction//

Dynamic Programming Introduction

    - those who cannot remember the past are condemned to repeat it 
    - DP is just using the alreasu computed ans for the sub problems for solving a bigger problem 

Two common DP approaches 
    - memoisation - top down DP , usually the problem is solved in the direction of the main problem to the base case 
    - tabulation - bottom up - usually the problem is solved in the direction of solving the base case to the main problem 

steps - 
    - try to convert the problelm in terms of indices 
    - do all possible stuffs on the index according to problem statament
    - sum of all stuffs - count all ways 

steps to memoise
    - create a dp[n+1] array initialises to -1
    - whenever we went to find the ans to a particular value we first check whether the ans is 
        already calculated using the dp array, if yes, simmply return the value from the dp array 
    - if not, then we are finding tje ans  for the given value for the first time, we will use the recusrive relation as usual 
        but before returning from the funuction, we will set dp[n] to the solution we get 

steps to tabultion
    - Declare a dp[] array of size n+1.
    - First initialize the base condition values, i.e i=0 and i=1 of the dp array as 0 and 1 respectively.
    - Set an iterative loop that traverses the array( from index 2 to n) and for every index set its value as dp[i-1] + dp[i-2]. 

steps to space optimise it 
    - each iteration's cur and prev becommes the next iteration prrev and prev2 respectibely
    - therefore after calculating cur , if we update prev and prev2 according to the next step, we will always get the answer
    - after the iterative loop has ended we can simply return prev as our answer

    