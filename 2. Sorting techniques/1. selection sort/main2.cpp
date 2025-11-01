#include <bits/stdc++.h>
using namespace std;

void stableSelectionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted part
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Instead of swapping, we shift elements right
        int key = arr[minIndex];
        while (minIndex > i) {
            arr[minIndex] = arr[minIndex - 1];
            minIndex--;
        }
        arr[i] = key;
    }
}

int main() {
    vector<int> arr = {4, 5, 3, 4, 1, 3};
    
    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    stableSelectionSort(arr);
    
    cout << "Sorted array (Stable Selection Sort): ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
