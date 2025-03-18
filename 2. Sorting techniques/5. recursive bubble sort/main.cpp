// https://www.geeksforgeeks.org/problems/bubble-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bubble-sort

// https://takeuforward.org/arrays/recursive-bubble-sort-algorithm/

#include <iostream>
#include <vector>
using namespace std;

void bubbleSortRecursive(vector<int> &arr, int n)
{
    // Base case: If the array has only one element, it's already sorted
    if (n == 1)
        return;

    // Perform one pass of Bubble Sort (push the largest element to the end)
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }

    // Recursive call to sort the first (n-1) elements
    bubbleSortRecursive(arr, n - 1);
}

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1};
    int n = arr.size();

    cout << "Original Array: ";
    for (auto ele : arr)
        cout << ele << " ";
    cout << endl;

    bubbleSortRecursive(arr, n);

    cout << "Sorted Array: ";
    for (auto ele : arr)
        cout << ele << " ";
    cout << endl;

    return 0;
}
/*

---

### **Time and Space Complexity Analysis:**

#### **Time Complexity:**
1. **Worst Case (Reverse Sorted Input):**  
   - In the worst case, every element is in descending order, requiring the maximum number of swaps.
   - Bubble Sort makes `n-1` passes, where each pass does up to `n-1` comparisons in the first pass, `n-2` in the second, and so on.
   - **T(n) = T(n-1) + (n-1) → O(n²)**
   - **Worst-case time complexity: O(n²)**

2. **Best Case (Already Sorted Input):**  
   - In an optimized iterative version, we could stop early if no swaps occur. However, this recursive version will still make `n-1` recursive calls.
   - **Best-case time complexity: O(n²)** (due to the recursive calls)

3. **Average Case Complexity:**  
   - Even with random ordering, the number of swaps remains approximately `O(n²)`.
   - **Average-case time complexity: O(n²)**

#### **Space Complexity:**
- **Recursive function call stack takes O(n) space** since `n-1` function calls are made before reaching the base case.
- **No extra data structures are used, so auxiliary space is O(1).**
- **Total space complexity: O(n) (due to recursion stack).**

---

### **Summary of Complexities:**
| Case        | Time Complexity | Space Complexity |
|------------|----------------|------------------|
| Best Case  | O(n²)          | O(n)            |
| Worst Case | O(n²)          | O(n)            |
| Average Case | O(n²)       | O(n)            |

💡 **Recursive Bubble Sort is not efficient for large datasets due to its O(n²) time complexity.** However, it helps in understanding recursion better. 🚀


*/