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
        bool flag = false;

        ListNode* temp = head;
        unordered_map<ListNode*, int> mp;

        while(temp != nullptr) {
            if(mp.count(temp) != 0) {
                flag = true;
                break;
            }
            mp[temp] = 1;
            temp = temp->next;
        }

        return flag;
    }
};




/*

Time Complexity: O(N) The code traverses the entire linked list once, where 'N' is the number of nodes in the list. Therefore, the time complexity is linear, O(N).

Space Complexity : O(N) The code uses a hash map/dictionary to store encountered nodes, which can take up to O(N) additional space, where 'n' is the number of nodes in the list. Hence, the space complexity is O(N) due to the use of the map to track nodes.

*/