// postoprder using one staxk is also possible

// here is its solution which i tried

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        stack<TreeNode*> st;
        TreeNode* current = root;
        TreeNode* lastVisited = nullptr;

        while (!st.empty() || current != nullptr) {
            if (current != nullptr) {
                st.push(current);
                current = current->left;
            } else {
                TreeNode* peekNode = st.top();
                // if right child exists and not visited
                if (peekNode->right != nullptr && lastVisited != peekNode->right) {
                    current = peekNode->right;
                } else {
                    result.push_back(peekNode->val);
                    lastVisited = peekNode;
                    st.pop();
                }
            }
        }

        return result;
    }
};
