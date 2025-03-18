// https://www.geeksforgeeks.org/problems/find-all-factorial-numbers-less-than-or-equal-to-n3548/0?problemType=functional&difficulty%255B%255D=-1&page=1&query=problemTypefunctionaldifficulty%255B%255D-1page1

// https://takeuforward.org/data-structure/factorial-of-a-number-iterative-and-recursive/

#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
   
   // Base Condition.
   if(n == 0)
   {
       return 1;
   }

   // Problem broken down into 2 parts and then combined.
   return n * factorial(n-1);

}

int main(){
  
  // Here, let’s take the value of n to be 3.
  int n = 5;
  cout<<factorial(n)<<endl;
  return 0;

}