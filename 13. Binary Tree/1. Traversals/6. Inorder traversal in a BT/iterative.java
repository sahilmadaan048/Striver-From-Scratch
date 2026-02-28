import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

// Define the TreeNode structure
class TreeNode {
    int data;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { data = x; left = null; right = null; }
}

class Solution {
    // Function to perform inorder traversal of a binary tree iteratively
    public List<Integer> inorder(TreeNode root) {
        Stack<TreeNode> st = new Stack<>();
        TreeNode node = root;
        
        List<Integer> inorder = new ArrayList<>();

        while(true) {
            if(node != null) {
                st.push(node);
                node = node.left;
            }
            else {
                if(st.isEmpty()) {
                    break;
                }
                node = st.pop();
                inorder.add(node.data);
                node = node.right;
            }
        }
    }
}

// Main class for testing
public class iterative {
    public static void main(String[] args) {
        // Creating a binary tree
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        // Initializing the Solution class
        Solution sol = new Solution();

        // Getting the inorder traversal
        List<Integer> result = sol.inorder(root);

        // Displaying the inorder traversal result
        System.out.print("Inorder Traversal: ");
        for (int val : result) {
            System.out.print(val + " ");
        }
        System.out.println();
    }
}

/*
time complexity => o(n) => n = noes in the binary tree, each node is visited exactly once

space complexity => o(h) => where h is the height of the binary tree this is the space required for the 
stack to store upo nodes during thr traversal

*/