// https://takeuforward.org/data-structure/vertical-order-traversal-of-binary-tree/


// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/description/





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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) {
            return ans;
        }

        // col -> level -> nodes at that position
        map<int, map<int, multiset<int>>> nodes;

        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; ++i) {
                auto it = q.front();
                q.pop();

                TreeNode* node = it.first;
                int col = it.second.first;
                int level = it.second.second;

                nodes[col][level].insert(node->val);

                if(node->left) {
                    q.push({node->left, {col - 1, level + 1}});
                }
                if(node->right) {
                    q.push({node->right, {col + 1, level + 1}});
                }
            }
        }

        for(auto& p : nodes){
            vector<int> colVals;
            for(auto& q : p.second){
                colVals.insert(colVals.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(colVals);
        }

        return ans;
    }
};



/*


Time Complexity: O(N * log2N * log2N * log2N) where N represents the number of nodes in the Binary Tree.

Postorder Traversal performed using BFS as a time complexity of O(N) as we are visiting each and every node once.
Multiset Operations to insert overlapping nodes at a specific vertical and horizontal level also takes O(log2N) complexity.
Map operations involve insertion and retrieval of nodes with their vertical and level as their keys. Since there are two nested maps, the total time complexity becomes O(log2N)*O(log2N).
Space Complexity: O(N + N/2) where N represents the number of nodes in the Binary Tree.

The map for storing nodes based on their vertical and level information occupies an additional space complexity of O(N) as it stores all N nodes of the Binary Tree.
The queue for breadth first traversal occupies a space proportional to the maximum level of the tree which can be O(N/2) in the worst case of a balanced tree

*/