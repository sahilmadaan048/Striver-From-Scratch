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
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> temp;
        ListNode* node = head;

        while(node != nullptr) {
            temp.push_back(node->val);
            node = node->next;
        }

        int n = temp.size();
        for(int i=0; i<n/k; i++) {
            reverse(temp.begin() + (i*k), temp.begin() + (i+1) * k);
        }

        node = head;
        int i = 0;
        while(node != nullptr) {
            node->val = temp[i];
            i++;
            node = node->next; 
        }

        return head;
    }
};