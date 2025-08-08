// https://leetcode.com/problems/rotate-list/

// https://takeuforward.org/data-structure/rotate-a-linked-list/

x/**
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
    void insertNode(ListNode* &head,int val) {
        ListNode* newNode = new ListNode(val);
        if(head == NULL) {
            head = newNode;
            return;
        }
        ListNode* temp = head;
        while(temp->next != NULL) temp = temp->next;
        
        temp->next = newNode;
        return;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL or head->next == NULL or k == 0) {
            return head;
        }

        ListNode* temp = head;
        int length = 1;

        while(temp->next != nullptr) {
            length++;
            temp = temp->next;
        }

        temp->next = head;

        k = (k % length); // ehen k is miore then the length of the arary

        int end = length - k;

        while(end--) {
            temp = temp->next;
        }
        head = temp->next;
        temp->next = nullptr;

        return head;
    }
};
