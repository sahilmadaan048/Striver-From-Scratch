// https://takeuforward.org/data-structure/starting-point-of-loop-in-a-linked-list/

// https://leetcode.com/problems/linked-list-cycle-ii/description/



class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp = head;

        unordered_map<ListNode* , int > mpp;

        while(temp != nullptr) {
            if(mpp.count(temp) != 0) {
                return temp;
            }
            mpp[temp]=1;
            temp = temp->next;
        }

        return nullptr;
    }
};


/*

Time Complexity: O(N) The code traverses the entire linked list once, where 'N' is the number of nodes in the list. Therefore, the time complexity is linear, O(N).

Space Complexity : O(N) The code uses a hash map/dictionary to store encountered nodes, which can take up to O(N) additional space, where 'n' is the number of nodes in the list. Hence, the space complexity is O(N) due to the use of the map to track nodes.

*/