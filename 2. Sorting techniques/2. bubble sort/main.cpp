// https://www.geeksforgeeks.org/problems/bubble-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bubble-sort

// https://takeuforward.org/data-structure/bubble-sort-algorithm/


#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr, int n){
    for(int i=0; i<n; i++) {
        bool swapped = false;
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        } 
        if(!swapped) break; //means it is already sorted array
    }   
    return;
}

int main() {
    vector<int> arr = {5, 4, 3, 2, 1};
    int n = arr.size();
    for(auto ele: arr){
        cout << ele << " ";
    }
    cout << endl;
    bubbleSort(arr, n);
    for(auto ele: arr){
        cout << ele << " ";
    }
    return 0;
}