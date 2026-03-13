// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

// https://takeuforward.org/data-structure/serialize-and-deserialize-a-binary-tree


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        if (!root) {
            return "";
        }

        string s = "";

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curNode = q.front();
            q.pop();

            if (curNode == nullptr) {
                s += "#,";
            } 
            else {
                s += to_string(curNode->val) + ",";

                q.push(curNode->left);
                q.push(curNode->right);
            }
        }

        return s;
    }
    // Function to deserialize a string and reconstruct the binary tree
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }
        stringstream s(data);
        string str;

        getline(s, str, ',');

        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            getline(s, str, ',');
            if (str != "#") {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');

            if (str != "#") {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));


/*

Complexity Analysis

Time Complexity: O(N)

serialize function: O(N), where N is the number of nodes in the tree. This is because the function performs a level-order traversal of the tree, visiting each node once.
deserialize function: O(N), where N is the number of nodes in the tree. Similar to the serialize function, it processes each node once while reconstructing the tree.
Space Complexity: O(N)

serialize function: O(N), where N is the maximum number of nodes at any level in the tree. In the worst case, the queue can hold all nodes at the last level of the tree.
deserialize function: O(N), where N is the maximum number of nodes at any level in the tree. The queue is used to store nodes during the reconstruction process, and in the worst case, it may hold all nodes at the last level

*/