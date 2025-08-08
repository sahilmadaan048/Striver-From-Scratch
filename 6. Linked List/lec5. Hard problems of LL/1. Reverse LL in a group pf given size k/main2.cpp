
// https://leetcode.com/problems/reverse-nodes-in-k-group/


// https://takeuforward.org/data-structure/reverse-linked-list-in-groups-of-size-k/

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
    // bool isValid(ListNode* kthNode, int k) {
    //     int i = 1;
    //     bool flag = false;
    //     ListNode* temp = kthNode;
    //     while(temp != nullptr) {
    //         i++;
    //         temp = temp->next;
    //     }
    //     if((i % k) == 0)  {
    //         flag = true;
    //     }
    //     return flag;
    //  }
    bool isValid(ListNode* node, int k) {
        int count = 0;
        while (node != nullptr && count < k) {
            node = node->next;
            count++;
        }
        return count == k;
    }


    // ListNode* getKthNode(ListNode* node, int k) {
    //     ListNode* temp = node;
    //     int i = 1;
    //     while(temp != nullptr) {
    //         temp = temp->next;
    //         i++;
    //         if(i == k) break;
    //     }
    //     return temp;
    // }
    ListNode* getKthNode(ListNode* node, int k) {
        int count = 1;
        while (node != nullptr && count < k) {
            node = node->next;
            count++;
        }
        return node;  // could be nullptr if not enough nodes
    }


    // void reverseTillKth(ListNode* temp, ListNode* kthNode) {
    //     ListNode* prev = nullptr;
    //     ListNode* curr = temp;

    //     while(curr != kthNode) {
    //         ListNode* agliNode = curr->next;

    //         curr->next = prev;
    //         prev = curr;
    //         curr = agliNode;
    //     }

    //     return;
    // }   
    ListNode* reverseTillKth(ListNode* head, ListNode* kthNode) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* stop = kthNode->next;

        while (curr != stop) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev; // new head of reversed group
    }

public:
    // ListNode* reverseKGroup(ListNode* head, int k) {
    //     if(!head || k <= 1) return head;

    //     ListNode* temp = head;

    //     while(temp != nullptr) {
    //         ListNode* kthNode = getKthNode(temp, k);
    //         reverseTillKth(temp, kthNode);
    //         if(isValid(kthNode, k)) temp = kthNode->next;
    //         else break;
    //     }

    //     return head;
    // }
        ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* groupPrev = &dummy;

        while (isValid(groupPrev->next, k)) {
            ListNode* groupStart = groupPrev->next;
            ListNode* groupEnd = getKthNode(groupStart, k);
            ListNode* nextGroupStart = groupEnd->next;

            // Reverse this group
            ListNode* newGroupHead = reverseTillKth(groupStart, groupEnd);

            // Connect previous group to new head
            groupPrev->next = newGroupHead;
            groupStart->next = nextGroupStart;

            // Move to next group
            groupPrev = groupStart;
        }

        return dummy.next;
    }
};