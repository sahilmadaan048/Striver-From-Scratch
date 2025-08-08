// https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1


// https://takeuforward.org/data-structure/bottom-view-of-a-binary-tree/




/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        
        if(root == nullptr) {
            return ans;
        }
        
        map<int, int> mpp; 
        queue<pair<Node*, int>> q; 
        
        q.push({root, 0});
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            
            Node* node = it.first;
            int line = it.second;
            
            // if(mpp.find(line) != mpp.end()) {
            // always update it
                mpp[line] = node->data;
            // }
            
            if(node->left != nullptr) {
                q.push({node->left, line - 1});
            }
            if(node->right != nullptr) {
                q.push({node->right, line + 1});
            }
        }
        
        for(auto& it : mpp) {
            ans.push_back(it.second);
        }
            
        return ans;
    }
};


/*

Time Complexity: O(N) where N is the number of nodes in the Binary Tree. This complexity arises from visiting each node exactly once during the BFS traversal.

Space Complexity: O(N/2 + N/2) where N represents the number of nodes in the Binary Tree.

The main space consuming data structure is the queue used for BFS traversal. It acquires space proportional to the number of nodes in the level it is exploring hence in the worst case of a balanced binary tree, the queue will have at most N/2 nodes which is the maximum width.
Additionally, the map is used to store the top view nodes based on their vertical positions hence its complexity will also be proportional to the greatest width level. In the worst case, it may have N/2 entries as well.


*/