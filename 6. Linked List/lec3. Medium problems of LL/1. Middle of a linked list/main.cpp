 // https://leetcode.com/problems/middle-of-the-linked-list/description/

// https://takeuforward.org/data-structure/find-middle-element-in-a-linked-list/


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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;

        if(head == NULL or head->next == NULL) {
            return head;
        }

        int cnt = 0;

        while(temp != NULL) {
            cnt++;
            temp = temp->next;
        }

        int mid = cnt / 2 + 1;

        temp = head;

        while(temp != nullptr) {
            mid = mid - 1;
            if(mid == 0) break;

            temp = temp->next;
        }

        return temp;
    }
};

/*


Time Complexity: O(N+N/2) The code traverses the entire linked list once and half times and then only half in the second iteration, first to count the number of nodes then then again to get to the middle node. Therefore, the time complexity is linear, O(N + N/2) ~ O(N).

Space Complexity : O(1) There is constant space complexity because it uses a constant amount of extra space regardless of the size of the linked list. We only use a few variables to keep track of the middle position and traverse the list, and the memory required for these variables does not depend on the size of the list.

*/