// https://www.geeksforgeeks.org/problems/merge-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=merge-sort

// https://takeuforward.org/data-structure/merge-sort-algorithm/

#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> &a, vector<int> &b)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int n1 = a.size();
    int n2 = b.size();

    vector<int> ans(n1 + n2);
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            ans[k++] = a[i++];
        }
        else if (b[j] < a[i])
        {
            ans[k++] = b[j++];
        }
    }

    while (i < n1)
    {
        ans[k++] = a[i++];
    }
    
    while (j < n2)
    {
        ans[k++] = b[j++];
    }

    return ans;
}

vector<int> mergesort(vector<int> &arr, int start, int end)
{
    if (start == end)
        return {arr[start]}; //reutn dinfle element vector

    //now i have to sort the arrrays by recursion
    int mid = start + (end - start)/2;
    vector<int> left = mergesort(arr, start, mid);
    vector<int> right = mergesort(arr, mid+1, end);
    
    return merge(left, right);
}

vector<int> mergeSort(vector<int> &arr, int n)
{
    return mergesort(arr, 0, n-1);
}

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1};
    int n = arr.size();
    for (auto ele : arr)
    {
        cout << ele << " ";
    }
    cout << endl;
    arr = mergeSort(arr, n);
    for (auto ele : arr)
    {
        cout << ele << " ";
    }
    return 0;
}