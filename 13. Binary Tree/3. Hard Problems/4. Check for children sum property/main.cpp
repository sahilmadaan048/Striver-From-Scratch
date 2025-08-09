// https://takeuforward.org/data-structure/check-for-children-sum-property-in-a-binary-tree/

// https://www.geeksforgeeks.org/dsa/check-for-children-sum-property-in-a-binary-tree/


// https://www.geeksforgeeks.org/problems/children-sum-parent/1


/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
    int isSumProperty(Node* root) {
    
    
        if (root == nullptr
            || (root->left == nullptr && root->right == nullptr))
            return 1;
            
        int sum = 0;
        
    
        if (root->left != nullptr)
            sum += root->left->data;
    
        if (root->right != nullptr)
            sum += root->right->data;
    
        return ((root->data == sum)
                && isSumProperty(root->left)
                && isSumProperty(root->right));
        
    }
};


/*

Time Complexity: O(N) where N is the number of nodes in the binary tree. This is because the algorithm traverses each node exactly once, performing constant-time operations at each node.

Space Complexity: O(N) where N is the number of nodes in the Binary Tree.

In the worst case scenario the tree is skewed and the auxiliary recursion stack space would be stacked up to the maximum height of the tree, resulting in a space complexity of O(N).
In the optimal case of a balanced tree, the auxiliary space would take up space proportional to O(log2N).


*/