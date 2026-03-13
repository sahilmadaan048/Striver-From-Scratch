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
    unordered_map<int, vector<int>> mpp;
public: 
    void solve(TreeNode* root) {
        if(!root->left and !root->right) {
            return;
        }

        if(root->left) {
            mpp[root->val].push_back(root->left->val);
            mpp[root->left->val].push_back(root->val);
            solve(root->left);
        }
        
        if(root->right) {
            mpp[root->val].push_back(root->right->val);
            mpp[root->right->val].push_back(root->val);
            solve(root->right);
        }
        return;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;

        if(!root) return ans;
        solve(root);

        queue<int> q;

        if(!target) {
            return ans;
        }

        vector<int> vis(600);
        q.push(target->val);
        vis[target->val] = 1;

        int level = 0;  


        while(!q.empty()) {
            if(level == k) break;    
            int size = q.size();

            for(int i=0; i<size; i++) {
                int node = q.front();
                q.pop();

                // vis[node] = 1;

                for(auto ele: mpp[node]) {
                    if(!vis[ele]) {
                        q.push(ele);
                        vis[ele] = 1;
                    }
                }
            }
            level += 1;
        }

        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};
