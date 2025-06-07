//  https://takeuforward.org/arrays/floor-and-ceil-in-sorted-array/

/*



Problem Statement: You're given an sorted array arr of n integers and an integer x. Find the floor and ceiling of x in arr[0..n-1].
The floor of x is the largest element in the array which is smaller than or equal to x.
The ceiling of x is the smallest element in the array greater than or equal to x.

Pre-requisite: Lower Bound & Binary Search

Example 1:
Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 5
Result: 4 7
Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.

Example 2:
Input Format: n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 8
Result: 8 8
Explanation: The floor of 8 in the array is 8, and the ceiling of 8 in the array is also 8.
Solution
Disclaimer: Don't jump directly to the solution, try it out yourself first.

Problem Link.

Solution:
We are going to solve this problem using the concepts of Lower Bound and Binary Search. 

The primary objective of the Binary Search algorithm is to efficiently determine the appropriate half to eliminate, thereby reducing the search space by half. It does this by determining a specific condition that ensures that the target is not present in that half.

What is the floor of x?
The floor of x is the largest element in the array which is smaller than or equal to x( i.e. largest element in the array <= x).

What is the ceiling of x?
The ceiling of x is the smallest element in the array greater than or equal to x( i.e. smallest element in the array >= x).

From the definitions, we can easily understand that the ceiling of x is basically the lower bound of x. The lower bound algorithm returns the index of x if x is present in the array and otherwise, it returns the index of the smallest element in the array greater than x.

The implementation of Ceil will be the same as the lower bound algorithm.

But we have no such algorithm prepared for the floor. So, we will implement the floor algorithm based on the Binary Search algorithm. The only difference in the algorithm compared to the lower bound algorithm will be the conditions. In this case,

If arr[mid] <= x: arr[mid] is a possible answer. So, we will store it and will try to find a larger number that satisfies the same condition. That is why we will remove the left half and try to find the number in the right half.
If arr[mid] > x: The arr[mid] is definitely not the answer and we need a smaller number. So, we will reduce the search space to the left half by removing the right half.
The rest of the part of the algorithm will be exactly the same.

Note: If the algorithm returns invalid indices which means there is no floor or ceiling of x, we will return -1.

Note: Remember, here we are told to find the numbers not the indices. So, we will store the numbers instead of indices in the ans variable.

Algorithm / Intuition:
Ceil:
We will declare the 2 pointers and an ‘ans’ variable initialized to -1(If we don’t find any index, we will return -1).

Place the 2 pointers i.e. low and high: Initially, we will place the pointers like this: low will point to the first index and high will point to the last index.
Calculate the ‘mid’: Now, we will calculate the value of mid using the following formula:
mid = (low+high) // 2 ( ‘//’ refers to integer division)
Compare arr[mid] with x: With comparing arr[mid] to x, we can observe 2 different cases:
Case 1 - If arr[mid] >= x: This condition means that the index arr[mid] may be an answer. So, we will update the ‘ans’ variable with arr[mid] and search in the left half if there is any smaller number that satisfies the same condition. Here, we are eliminating the right half.
Case 2 - If arr[mid] < x: In this case, arr[mid] cannot be our answer and we need to find some bigger element. So, we will eliminate the left half and search in the right half for the answer.
The above process will continue until the pointer low crosses high.

Floor: 
We will declare the 2 pointers and an ‘ans’ variable initialized to -1 (If we don’t find any index, we will return -1).

Place the 2 pointers i.e. low and high: Initially, we will place the pointers like this: low will point to the first index and high will point to the last index.
Calculate the ‘mid’: Now, we will calculate the value of mid using the following formula:
mid = (low+high) // 2 ( ‘//’ refers to integer division)
Compare arr[mid] with x: With comparing arr[mid] to x, we can observe 2 different cases:
Case 1 - If arr[mid] <= x: The index arr[mid] is a possible answer. So, we will store it and will try to find a larger number that satisfies the same condition. That is why we will remove the left half and try to find the number in the right half.
Case 2 - If arr[mid] > x: arr[mid] is definitely not the answer and we need a smaller number. So, we will reduce the search space to the left half by removing the right half.
The above process will continue until the pointer low crosses high.

Dry run: Please refer video for it.



*/