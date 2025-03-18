// https://takeuforward.org/data-structure/remove-duplicates-in-place-from-sorted-array/

// https://takeuforward.org/data-structure/remove-duplicates-in-place-from-sorted-array/

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        // one method is by using sets
        // i dont want to use that method
        int n = nums.size();
        int i = 0;
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[i] != nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};

/*
Intuition: We can think of using two pointers ‘i’ and ‘j’, we move ‘j’ till we don't get a number arr[j] which is different from arr[i]. As we got a unique number we will increase the i pointer and update its value by arr[j].

Approach:
Take a variable i as 0;
Use a for loop by using a variable ‘j’ from 1 to length of the array.
If arr[j] != arr[i], increase ‘i’ and update arr[i] == arr[j].
 After completion of the loop return i+1, i.e size of the array of unique elements.

*/