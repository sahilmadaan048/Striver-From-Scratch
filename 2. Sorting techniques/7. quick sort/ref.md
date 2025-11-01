Perfect 👌 — let’s go step by step and deeply understand this **Quick Sort** code you shared (from Striver’s DSA series).
We’ll cover **how it works**, **each part of the code**, **why it’s written this way**, and also discuss **time complexity**, **space complexity**, and **stability**.

---

## 🧠 1. What is Quick Sort?

**Quick Sort** is a **Divide and Conquer** sorting algorithm.

It works by:

1. Picking a **pivot element**.
2. **Partitioning** the array — placing all smaller elements to its left, larger ones to its right.
3. **Recursively** sorting the left and right parts.

---

## ⚙️ 2. Code Breakdown

Let’s analyze it section by section.

---

### ### 🧩 Function: `partition()`

```cpp
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}
```

#### 💡 Step-by-step explanation:

1. **Choose pivot**

   ```cpp
   int pivot = arr[low];
   ```

   * We pick the **first element** as the **pivot**.
   * Pivot helps divide the array into two halves:

     * Left → elements smaller than pivot
     * Right → elements greater than pivot

---

2. **Initialize pointers**

   ```cpp
   int i = low;
   int j = high;
   ```

   * `i` scans from **left to right**.
   * `j` scans from **right to left**.

---

3. **Move `i` right until element > pivot**

   ```cpp
   while (arr[i] <= pivot && i <= high - 1)
       i++;
   ```

   * `i` stops when we find an element **greater** than pivot (which should go right side).

---

4. **Move `j` left until element <= pivot**

   ```cpp
   while (arr[j] > pivot && j >= low + 1)
       j--;
   ```

   * `j` stops when we find an element **smaller or equal** to pivot (which should go left side).

---

5. **Swap if i < j**

   ```cpp
   if (i < j)
       swap(arr[i], arr[j]);
   ```

   * This ensures misplaced elements on both sides get corrected.
   * We keep swapping until pointers cross each other.

---

6. **Finally, place pivot in correct position**

   ```cpp
   swap(arr[low], arr[j]);
   return j;
   ```

   * After the loop ends, `j` points to the **last element smaller than pivot**.
   * Swapping places the pivot at its **sorted position** in the array.

---

### 📊 Example dry run

**Array:** `[4, 6, 2, 5, 7, 9, 1, 3]`
`pivot = 4`, `low = 0`, `high = 7`

| Step               | i              | j           | arr[i]           | arr[j]                                                  | Action                                 |
| ------------------ | -------------- | ----------- | ---------------- | ------------------------------------------------------- | -------------------------------------- |
| Start              | 0              | 7           | 4                | 3                                                       | -                                      |
| Move i             | i=1 (6>4 stop) |             |                  |                                                         | i stops                                |
| Move j             |                | j=7→6→5→4→3 | arr[j]=3<=4 stop | Swap arr[i]=6 and arr[j]=3 → `[4, 3, 2, 5, 7, 9, 1, 6]` |                                        |
| Continue until i≥j | …              | …           | …                | …                                                       | Eventually pivot 4 swaps with arr[j]=3 |

Final after partition:
`[3, 2, 1, 4, 7, 9, 5, 6]`
Now pivot `4` is in correct position.

---

### ### 🧩 Function: `qs()` — Recursive Quick Sort

```cpp
void qs(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);  // sort left half
        qs(arr, pIndex + 1, high); // sort right half
    }
}
```

#### Explanation:

* **Base case:** if the subarray has 1 or 0 elements, it’s already sorted.
* **Recursive case:**

  * Partition the array → get correct position `pIndex` of pivot.
  * Recursively sort:

    * Left part: `low → pIndex-1`
    * Right part: `pIndex+1 → high`

---

### ### 🧩 Function: `quickSort()`

```cpp
vector<int> quickSort(vector<int> arr)
{
    qs(arr, 0, arr.size() - 1);
    return arr;
}
```

This just calls the recursive quick sort function `qs()` with full range of array indices.

---

### ### 🧩 `main()` Function

Just for testing:

```cpp
vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
```

* Print array before sorting
* Call `quickSort()`
* Print array after sorting

Output:

```
Before Using quick Sort:
4 6 2 5 7 9 1 3
After Using quick sort:
1 2 3 4 5 6 7 9
```

---

## ⚡ 3. Time & Space Complexity

| Case                 | Time Complexity                                     | Explanation                                                                               |
| -------------------- | --------------------------------------------------- | ----------------------------------------------------------------------------------------- |
| **Best Case**        | O(n log n)                                          | pivot divides array evenly each time                                                      |
| **Average Case**     | O(n log n)                                          | typical random pivot                                                                      |
| **Worst Case**       | O(n²)                                               | happens if array is already sorted or reverse sorted and pivot always chosen from one end |
| **Space Complexity** | O(1) auxiliary (in-place), O(log n) recursion stack |                                                                                           |

---

## ⚠️ 4. Is Quick Sort Stable?

❌ **No, Quick Sort is *not stable*.**

Reason:

* It uses **swapping** during partitioning.
* Equal elements can change their relative order after being swapped.

However, a **modified stable version** can be created (using extra space and stable partition logic).

---

## ✅ 5. Summary

| Property     | Quick Sort          |
| ------------ | ------------------- |
| Type         | Divide & Conquer    |
| Pivot        | arr[low] (can vary) |
| In-place     | ✅ Yes               |
| Stable       | ❌ No                |
| Best Case    | O(n log n)          |
| Worst Case   | O(n²)               |
| Average Case | O(n log n)          |

---

Would you like me to also show a **dry run animation or step-by-step array trace** (with indices and swaps shown visually) for this same input `{4,6,2,5,7,9,1,3}`? It makes understanding partitioning crystal clear.
