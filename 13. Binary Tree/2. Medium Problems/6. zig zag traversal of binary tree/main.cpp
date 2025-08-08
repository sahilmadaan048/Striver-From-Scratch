// https://takeuforward.org/data-structure/zig-zag-traversal-of-binary-tree/


// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/



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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(root == nullptr) {
            return ans;
        }

        queue<TreeNode*> q;
        bool flag = 1;

        q.push(root);

        while(!q.empty()) {
            int sz = q.size();
            vector<int> row(sz);
            for(int i=0; i<sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                int index = flag == 1 ? i : (sz - i - 1);  
        
                row[index] = node->val;
            
            
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);

            }
            
            flag = !flag;
            ans.push_back(row);
        }

        return ans;
    }
};


/*

Time Complexity: O(N) where N is the number of nodes in the binary tree. Each node of the binary tree is enqueued and dequeued exactly once, hence all nodes need to be processed and visited. Processing each node takes constant time operations which contributes to the overall linear time complexity.

Space Complexity: O(N) where N is the number of nodes in the binary tree. In the worst case, the queue has to hold all the nodes of the last level of the binary tree, the last level could at most hold N/2 nodes hence the space complexity of the queue is proportional to O(N). The resultant vector answer also stores the values of the nodes level by level and hence contains all the nodes of the tree contributing to O(N) space as well.

*/