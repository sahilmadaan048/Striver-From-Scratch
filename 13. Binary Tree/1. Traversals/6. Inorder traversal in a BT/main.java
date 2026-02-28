import java.util.*;

class Node {
    int data;
    Node left;
    Node right;

    Node(int val) {
        data = val;
        left = null;
        right = null;
    }
}

class Solution {
    public void inorder(Node root, List<Integer> arr) {
        if(root == null) {
            return;
        }

        inorder(root.left, arr);
        arr.add(root.data);
        inorder(root.right, arr);
    }

    public List<Integer> inOrder(Node root) {
        List<Integer> arr = new ArrayList<>();
        inorder(root, arr);

        return arr;
    }
}

public class main {
    public static void main(string[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
    
        Solution sol = new Solution();
        
        List<Integer> result = sol.inOrder(root);

        System.out.println("Inorder Traversal: ");

        for(int val : result) {
            System.out.print(val + " ");
        }

        System.out.println();
    }
}


/*

time complexity => O(n) => we process each node once fo the traversal

space complexity => O(n) => extra space used foro storing the preorder traversal and the recusrive stack 

*/

