// MIN HEAP implementation

// https://www.geeksforgeeks.org/dsa/introduction-to-min-heap-data-structure/

#include <iostream>
#include <vector>

using namespace std;

// Function to insert a new element into the min-heap
void insert_min_heap(vector<int>& heap, int value)
{
    // Add the new element to the end of the heap
    heap.push_back(value);
    // Get the index of the last element
    int index = heap.size() - 1;
    // Compare the new element with its parent and swap if
    // necessary
    while (index > 0
           && heap[(index - 1) / 2] > heap[index]) {
        swap(heap[index], heap[(index - 1) / 2]);
        // Move up the tree to the parent of the current
        // element
        index = (index - 1) / 2;
    }
}

// Main function to test the insert_min_heap function
int main()
{
    vector<int> heap;
    int values[] = { 10, 7, 11, 5, 4, 13 };
    int n = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < n; i++) {
        insert_min_heap(heap, values[i]);
        cout << "Inserted " << values[i]
             << " into the min-heap: ";
        for (int j = 0; j < heap.size(); j++) {
            cout << heap[j] << " ";
        }
        cout << endl;
    }
    return 0;
}