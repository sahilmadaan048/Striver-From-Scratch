// https://www.youtube.com/watch?v=YitR4dQsddE`
// https://takeuforward.org/plus/dsa/problems/find-pairs-with-given-sum-in-doubly-linked-list?tab=editorial

// find all paris with given sum in a ll

/*
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* prev;

    ListNode(int value) : val(value), next(nullptr), prev(nullptr) {}

    ~ListNode() {
        delete next;
    }
};
*/
class Solution
{
    ListNode* findTail(ListNode* head) {
        if (!head) return nullptr;
        while (head->next) head = head->next;
        return head;
    }

public:
    vector<vector<int>> findPairsWithGivenSum(ListNode *head, int target)
    {
        vector<vector<int>> ans;
        if (!head || !head->next) return ans;

        ListNode* left = head;
        ListNode* right = findTail(head);

        while (left != right && left->prev != right) {
            int sum = left->val + right->val;

            if (sum == target) {
                ans.push_back({left->val, right->val});
                left = left->next;
                right = right->prev;
            }
            else if (sum < target) {
                left = left->next;
            }
            else {
                right = right->prev;
            }
        }

        return ans;
    }
};


/*
O(n)

*/