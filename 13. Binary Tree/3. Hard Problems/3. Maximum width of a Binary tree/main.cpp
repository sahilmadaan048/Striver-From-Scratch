// https://leetcode.com/problems/maximum-width-of-binary-tree/description/


// https://takeuforward.org/data-structure/maximum-width-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if(!root) return 0;

        int maxi = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});


        while(!q.empty()) {
            int size = q.size();
            long long mmin = q.front().second;
            int first, last;            
            for(int i=0; i<size; i++) {
                long long curr = q.front().second - mmin;

                TreeNode* node = q.front().first;
                q.pop();

                if(i == 0) {
                    first = curr;
                }

                if(i == size-1) {
                    last = curr;
                }
                if (node->left) {
                    q.push({node->left, curr * 2 + 1});
                }

                if (node->right) {
                    q.push({node->right, curr * 2 + 2});
                }
            }
            
            maxi = max(maxi, last - first + 1);
        }

        return maxi;
    }
};


/*


Time Complexity: O(N) where N is the number of nodes in the binary tree. Each node of the binary tree is enqueued and dequeued exactly once, hence all nodes need to be processed and visited. Processing each node takes constant time operations which contributes to the overall linear time complexity.

Space Complexity: O(N) where N is the number of nodes in the binary tree. In the worst case, the queue has to hold all the nodes of the last level of the binary tree, the last level could at most hold N/2 nodes hence the space complexity of the queue is proportional to O(N).

*/

