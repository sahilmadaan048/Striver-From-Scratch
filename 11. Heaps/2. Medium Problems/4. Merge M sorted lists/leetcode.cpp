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
    ListNode* mergeTwo(ListNode* head1, ListNode* head2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        while(head1 != nullptr and head2 != nullptr) {
            if(head1->val <= head2->val) {
                curr->next = head1;
                head1 = head1->next;
            }
            else {
                curr->next = head2;
                head2 = head2->next;
            }
            curr = curr->next;
        }

        if(head1 != nullptr) {
            curr->next = head1;
        }
        else {
            curr->next = head2;
        }

        return dummy->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode* res = nullptr;

        for(auto node: lists) {
            res = mergeTwo(res, node);
        }

        return res;
    }
};