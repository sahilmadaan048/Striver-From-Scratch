// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if(node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        markParents(root, parent);

        unordered_set<TreeNode*> visited;
        queue<pair<TreeNode*, int>> q;
        q.push({target, 0});
        visited.insert(target);

        while(!q.empty()) {
            auto [node, dist] = q.front();
            q.pop();

            if(dist == k) {
                vector<int> ans;
                ans.push_back(node->val);

                // Gather all nodes remaining in queue with same dist
                while(!q.empty()) {
                    ans.push_back(q.front().first->val);
                    q.pop();
                }
                return ans;
            }

            if(node->left && !visited.count(node->left)) {
                visited.insert(node->left);
                q.push({node->left, dist + 1});
            }
            if(node->right && !visited.count(node->right)) {
                visited.insert(node->right);
                q.push({node->right, dist + 1});
            }
            if(parent.count(node) && !visited.count(parent[node])) {
                visited.insert(parent[node]);
                q.push({parent[node], dist + 1});
            }
        }
        return {};
    }
};



