// https://takeuforward.org/arrays/recursive-insertion-sort-algorithm/


// https://www.geeksforgeeks.org/problems/insertion-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=insertion-sort


#include <iostream>
#include <vector>
using namespace std;

// Recursive function for insertion sort
void insertionSortRecursive(vector<int> &arr, int n)
{
    // Base case: If array has only one element, it's already sorted
    if (n <= 1)
        return;

    // Sort first n-1 elements
    insertionSortRecursive(arr, n - 1);

    // Insert last element of the current subarray into its correct position
    int last = arr[n - 1];
    int j = n - 2;

    // Shift elements that are greater than last
    while (j >= 0 && arr[j] > last)
    {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = last;
}

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1};
    int n = arr.size();

    cout << "Original Array: ";
    for (auto ele : arr)
        cout << ele << " ";
    cout << endl;

    insertionSortRecursive(arr, n);

    cout << "Sorted Array: ";
    for (auto ele : arr)
        cout << ele << " ";
    cout << endl;

    return 0;
}


/*

### **Time and Space Complexity Analysis:**

#### **Time Complexity:**
1. **Worst Case (Reverse Sorted Input):**  
   - The worst case occurs when the array is sorted in descending order, requiring maximum shifts.
   - Every element needs to be compared and moved.
   - **T(n) = T(n-1) + O(n) → O(n²)**
   - **Worst-case time complexity: O(n²)**  

2. **Best Case (Already Sorted Input):**  
   - In the best case, each element is already in place, and no shifting is needed.
   - The recursion still runs but with minimal operations.
   - **Best-case time complexity: O(n)**  

3. **Average Case Complexity:**  
   - Random input still leads to an average of `O(n²)` comparisons and shifts.
   - **Average-case time complexity: O(n²)**  

#### **Space Complexity:**
- The recursive calls use **O(n) space** for the function call stack.
- No extra space is used apart from recursive function calls.
- **Total space complexity: O(n) (due to recursion stack).**

---

### **Summary of Complexities:**
| Case        | Time Complexity | Space Complexity |
|------------|----------------|------------------|
| Best Case  | O(n)           | O(n)            |
| Worst Case | O(n²)          | O(n)            |
| Average Case | O(n²)       | O(n)            |

💡 **Recursive Insertion Sort is inefficient for large datasets due to O(n²) time complexity but useful for learning recursion-based sorting.** 🚀

*/