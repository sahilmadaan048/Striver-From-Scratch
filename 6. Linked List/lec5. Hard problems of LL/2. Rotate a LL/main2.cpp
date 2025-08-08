// https://leetcode.com/problems/rotate-list/

// https://takeuforward.org/data-structure/rotate-a-linked-list/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;

        vector<int> arr;
        ListNode* temp = head;

        while (temp != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        int n = arr.size();
        k = k % n;  // Handle cases where k > n
        if (k == 0) return head;

        vector<int> rotated(n);
        for (int i = 0; i < n; i++) {
            rotated[(i + k) % n] = arr[i];
        }

        temp = head;
        int i = 0;
        while (temp != nullptr) {
            temp->val = rotated[i++];
            temp = temp->next;
        }

        return head;
    }
};



/*

Time Complexity: O(Number of nodes present in the list*k)

Reason: For k times, we are iterating through the entire list to get the last element and move it to first.

Space Complexity: O(1)

Reason: No extra data structures is used for computations


*/