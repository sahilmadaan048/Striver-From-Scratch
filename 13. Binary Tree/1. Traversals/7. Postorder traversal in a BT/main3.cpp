class Solution {
    public: 
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) {
            return ans;
        }

        stack<TreeNode*> st1, st2;

        st1.push(root);

        while(!st1.empty()) {
            TreeNode* node = st1.top();
            st1.pop();

            st2.push(node);

            if(node->left) st1.push(node->left);
            if(node->right) st1.push(node->right);
        }

        while(!st2.empty()) {
            ans.push_back(st2.top()->val);
            st2.pop();
        }

        return ans;
    }
};

/*

time complexity => o(n) => eevery node i spushed and popeed from the stacks
                            each node is processed a constant number of time
                            total ops is propertional to n

space complxity => o(n) => first stack can hold up to n  node
                            second stack also can hold up to n nodes
                            total auxillary space => o(n)


 */

 