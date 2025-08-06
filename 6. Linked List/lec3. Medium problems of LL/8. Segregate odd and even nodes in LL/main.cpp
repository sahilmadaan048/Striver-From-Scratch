// https://leetcode.com/problems/odd-even-linked-list/description/

// https://leetcode.com/problems/odd-even-linked-list/description/

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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Dummy heads and tails for even and odd lists
        ListNode* evenHead = new ListNode(-1);
        ListNode* oddHead = new ListNode(-1);
        ListNode* evenTail = evenHead;
        ListNode* oddTail = oddHead;

        ListNode* curr = head;

        int idx = 0;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = nullptr;

            if (idx % 2 == 1) {
                evenTail->next = curr;
                evenTail = curr;
            } else {
                oddTail->next = curr;
                oddTail = curr;
            }

            curr = nextNode;
            idx++;
        }

        // Connect odd list with even list
        oddTail->next = evenHead->next;

        return oddHead->next;
    }
};


/*

Time Complexity: O(N) N is the number of Nodes in LinkedList. As we are traversing LinkedList once.

Space Complexity: O(1) We are just Manipulating the Links, not using any extra space.



*/