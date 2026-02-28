class Solution {
    public:

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr) return ans;

        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* last = nullptr;

        while(curr != nullptr || !st.empty()) {
            if(Curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }
            else {
                TreeNode* node = st.top();

                if(node->right != nullptr && last != node->right) {
                    curr = node->right;
                }
                else {
                    ans.push_back(node->val);
                    last = node;
                    st.pop();
                }
            }
        }

        return ans;
    }
};

/*

Time Complexity
O(n)

Each node is pushed once.

Each node is popped once.

Constant work per node.

🔹 Space Complexity

O(n)

Only one stack used.

In worst case (skewed tree), stack holds all nodes.

So auxiliary space = O(n).

*/