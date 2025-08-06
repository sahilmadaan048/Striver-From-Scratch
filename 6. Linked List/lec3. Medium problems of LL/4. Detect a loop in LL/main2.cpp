// https://leetcode.com/problems/linked-list-cycle/description/

// https://takeuforward.org/data-structure/starting-point-of-loop-in-a-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
    
        bool flag = false;

        while(fast != nullptr and fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                slow = head;

                while(slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                flag = true;
                break;
            } 
        }

        return flag;
    }
};

/*

Time Complexity: O(N) The code traverses the entire linked list once, where 'n' is the number of nodes in the list. This traversal has a linear time complexity, O(n).

Space Complexity : O(1) The code uses only a constant amount of additional space, regardless of the linked list's length. This is achieved by using two pointers (slow and fast) to detect the loop without any significant extra memory usage, resulting in constant space complexity, O(1).

*/