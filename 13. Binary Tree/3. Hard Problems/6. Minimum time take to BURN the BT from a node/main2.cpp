
// All Nodes Distance K in Binary Tree => leetcode 

class Solution {
    unordered_map<int, vector<int>> mpp;

    void solve(TreeNode* root){
        if(!root) return;

        if(root->left){
            mpp[root->val].push_back(root->left->val);
            mpp[root->left->val].push_back(root->val);
            solve(root->left);
        }

        if(root->right){
            mpp[root->val].push_back(root->right->val);
            mpp[root->right->val].push_back(root->val);
            solve(root->right);
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        vector<int> ans;

        solve(root);

        queue<int> q;
        vector<int> vis(600);

        q.push(target->val);
        vis[target->val] = 1;

        int level = 0;

        while(!q.empty()){

            if(level == k) break;

            int size = q.size();

            for(int i=0;i<size;i++){
                int node = q.front();
                q.pop();

                for(auto ele: mpp[node]){
                    if(!vis[ele]){
                        q.push(ele);
                        vis[ele] = 1;
                    }
                }
            }

            level++;
        }

        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};