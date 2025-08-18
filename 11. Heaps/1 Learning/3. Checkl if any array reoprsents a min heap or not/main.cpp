// https://www.geeksforgeeks.org/dsa/how-to-check-if-a-given-array-represents-a-binary-heap/

#include <bits/stdc++.h>
using namespace std;

bool isHeap(int arr[], int i, int n) {
    // for leah node 
    // 2i + 1 >= n
    if(i >= (n-1)/2) return true;

    if(arr[i] >= arr[2*i+1] && 
        arr[i] >= arr[2*i+2] && 
        isHeap(arr, 2*i+1, n) &&
        isHeap(arr, 2*i+2, n)
    ) {
        return true;
    }

    return false;
}


// driver program
int main() {
    int arr[] = { 90, 15, 10, 7, 12, 2, 7, 3 };
    int n = sizeof(arr) / sizeof(int) - 1;

    isHeap(arr, 0, n) ? printf("Yes") : printf("No");

    return 0;   
}