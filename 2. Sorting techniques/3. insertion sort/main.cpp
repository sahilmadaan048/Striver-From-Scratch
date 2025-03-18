// https://www.geeksforgeeks.org/problems/insertion-sort/0?category%5B%5D=Algorithms&page=1&query=category%5B%5DAlgorithmspage1&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=insertion-sort

// https://takeuforward.org/data-structure/insertion-sort-algorithm/


#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr, int n){
    for(int i=0; i< n ; i++) {
        int j = i;
        while(j>0 and arr[j-1] >= arr[j]) {
            swap(arr[j-1], arr[j]);
            j--;
        }
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
    insertionSort(arr, n);
    for(auto ele: arr){
        cout << ele << " ";
    }
    return 0;
}