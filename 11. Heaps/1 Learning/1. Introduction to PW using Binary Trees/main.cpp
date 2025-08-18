// https://www.geeksforgeeks.org/dsa/priority-queue-using-binary-heap/


#include <bits/stdc++.h>
using namespace std;

// for a parent i
// function to return the iundex of the parent  node of a given node
int parent(int i) {
    return (i - 1) / 2;
}


// following 1 based indexing
// function to return the index of the left child of the given node
int leftChild(int i) {
    return ((2 * i) + 1);
}

// following 1 based indexing
// function to return the index of the right child of the given node
int rightChild(int i) {
    return ((2 * i) + 2);
}

// function to  shift down the node in order to mnabain the heap priority
void shiftDown(int i, vector<int>& arr, int &size) {
    int maxIndex = 1;

    // left child
    int l = leftChild(i);

    if(l <= size and arr[l] > arr[maxIndex]) {
        maxIndex = l;
    }

    // right child
    int r = rightChild(i);

    if(r <= size and arr[r] > arr[maxIndex]) {
        maxIndex = r;
    }

    // if i not same as maxIndex
    if(i != maxIndex) {
        swap(arr[i], arr[maxIndex]);
        shiftDown(maxIndex, arr, size);
    }
}

// function to extract the element with maximum priority
int extractMax(vector<int>& arr, int size) {
    int result = arr[0];

    // replace the value at the root
    // with the last leaf
    arr[0] = arr[size];
    size = size - 1;

    // shift down the replacement element 
    // to mantain the heap priority
    shiftDown(0, arr, size);
    return result;
}


// function to get the value of the curent maximum element
int getMax(vector<int>& arr) {
    return arr[0];
}



// finction to remove the element located at give index
void remove(int i, vector<int>& arr, int &size) {
    arr[i] = getMax(arr) + 1;

    // shift the node to the root of the heap
    shiftUp(i, arr);

    // extract th node
    extractMax(arr, size);
}

// finction to shift u[ the node in order
// to mantaion the heap
void shiftUp(int i, vector<int>& arr) {
    while (i>0 and arr[parent[i]] < arr[i])
    {
        swap(arr[parent(i)], arr[i]);
        i = parent[i];
    }
}

// function to insert a new element in the binary hea[p
void insert(int p, vector<int>& arr, int & size) {
    size = size + 1;
    arr.push_back(p);

    // shift up to mantain heap property
    shiftUp(size, arr);
}

int main() {
        /*         45
            /      \
           31      14
          /  \    /  \
         13  20  7   11
        /  \
       12   7
    Create a priority queue shown in
    example in a binary max heap form.
    Queue will be represented in the
    form of array as:

    45 31 14 13 20 7 11 12 7 */

    45 31 14 13 20 7 11 12 7

    // Insert the element to the
    // priority queue

    int size = -1;
    
    vector<int> arr;
    int size = -1;
    insert(45, arr, size);
    insert(20, arr, size);
    insert(14, arr, size);
    insert(12, arr, size);
    insert(31, arr, size);
    insert(7, arr, size);
    insert(11, arr, size);
    insert(13, arr, size);
    insert(7, arr, size);     


    int i = 0;


    // priotiy queue before extracting max 
    cout << "Priority Queue: " << endl;
    while(i<=size) {
        cout << arr[i] << " ";
        i++;
    }
    cout << endl;

    // node with maximum priority
    cout << "Node with maximum priority: " << extractMax(arr, size) << endl;
 
    // Priority queue after extracting max
    cout << "Priority queue after "
         << "extracting maximum : ";
    int j = 0;
    while (j <= size) {
        cout << arr[j] << " ";
        j++;
    }

    cout << endl;

    // Change the priority of element
    // present at index 2 to 49
    changePriority(2, 49, arr, size);
    cout << "Priority queue after "
         << "priority change : ";
    int k = 0;
    while (k <= size) {
        cout << arr[k] << " ";
        k++;
    }

    cout << endl;

    // Remove element at index 3
    remove(3, arr, size);
    cout << "Priority queue after "
         << "removing the element : ";
    int l = 0;
    while (l <= size) {
        cout << arr[l] << " ";
        l++;
    }
    return 0;
    

}