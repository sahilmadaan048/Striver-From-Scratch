// https://takeuforward.org/data-structure/remove-n-th-node-from-the-end-of-a-linked-list/

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fastPointer = head;
        ListNode* slowPointer = head;

        // move fastPointer n steps ahead
        for(int i = 0; i < n; i++) {
            fastPointer = fastPointer->next;
        }

        // if fastPointer is null after n steps, we need to delete head
        if(fastPointer == NULL) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        // move both until fastPointer->next is NULL
        while(fastPointer->next != NULL) {
            fastPointer = fastPointer->next;
            slowPointer = slowPointer->next;
        }

        // slowPointer is now just before the node to delete
        ListNode* delNode = slowPointer->next;
        slowPointer->next = delNode->next;
        delete delNode;

        return head;
    }
};


/*
Time Complexity: O(N) since the fast pointer will traverse the entire linked list, where N is the length of the linked list.

Space Complexity: O(1), as we have not used any extra space.

*/