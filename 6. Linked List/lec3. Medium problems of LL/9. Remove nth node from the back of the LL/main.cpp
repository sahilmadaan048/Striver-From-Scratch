// https://takeuforward.org/data-structure/remove-n-th-node-from-the-end-of-a-linked-list/

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return nullptr;
        int cnt = 0;
        ListNode* temp = head;

        while(temp != nullptr) {
            cnt++;
            temp = temp->next;
        }

        // if cnt equals m delete the head of the LL

        if(cnt == n) {  
            ListNode* newHead = head->next;
            delete head;
            return newHead; 
        }

        // position of the node to be deleyed from the head
        int res = cnt - n;
        temp = head;

        while(temp != nullptr) {
            res--;
            if(res == 0) break;
            temp = temp->next;
        }

        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete  (delNode);

        return head;
    }
};

/*

Time Complexity: O(L)+O(L-N), We are calculating the length of the linked list and then iterating up to the (L-N)th node of the linked list, where L is the total length of the list.

Space Complexity:  O(1), as we have not used any extra space.

*/