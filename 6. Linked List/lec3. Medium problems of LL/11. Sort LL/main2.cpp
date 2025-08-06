// https://takeuforward.org/linked-list/sort-a-linked-list

// https://leetcode.com/problems/sort-list/description/


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
    ListNode* mergeTwoSortedLinkedLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next; 
        }

        if (list1 != nullptr) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }
        return dummyNode->next;
    }

    ListNode* findMiddle(ListNode* head){
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr or head->next == nullptr) {
            return head;
        }

        ListNode* middle = findMiddle(head);


        ListNode* right = middle->next;
        middle->next = nullptr;
        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);

        return mergeTwoSortedLinkedLists(left, right);
    }

};


/*

Time Complexity: O(N log N)where N is the number of nodes in the linked list. Finding the middle node of the linked list requires traversing it linearly taking O(N) time complexity and to reach the individual nodes of the list, it has to be split log N times (continuously halve the list until we have individual elements).

Space Complexity : O(1) as no additional data structures or space is allocated for storage during the merging process. However, space proportional to O(log N) stack space is required for the recursive calls. THe maximum recursion depth of log N height is occupied on the call stack.

*/