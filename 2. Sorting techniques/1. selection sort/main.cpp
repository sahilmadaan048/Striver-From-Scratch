// https://www.geeksforgeeks.org/problems/selection-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=selection-sort

// https://takeuforward.org/sorting/selection-sort-algorithm/

//we have to do selection sort algorithm

//we will fin the minimum element in the i+1 to n range and then swap the first element of the iunpdred range with tthat mini eleme t and we will continute douingf so utnil
//the whole array is sorted


#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr, int n){
    //find the minimum element in the j+1 to n range and then swap arr[i] and arr[mini]
    for(int i=0; i<n-1; i++) {
        int mini = i;
        for(int j=i+1; j<n ; j++) {
            if(arr[j] < arr[mini]){
                mini = j;
            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }   
}

int main() {
    vector<int> arr = {5, 4, 3, 2, 1};
    int n = arr.size();
    for(auto ele: arr){
        cout << ele << " ";
    }
    cout << endl;
    selectionSort(arr, n);
    for(auto ele: arr){
        cout << ele << " ";
    }
    return 0;
}