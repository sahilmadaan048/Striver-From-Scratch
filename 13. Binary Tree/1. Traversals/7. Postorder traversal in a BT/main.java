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
    public void postorder(Node root, List<Integer> arr) {
        if(root == null) {
            return;
        }

        postorder(root.left, arr);
        postorder(root.right, arr);
        arr.add(root.data);
    }

    public List<Integer> postOrder(Node root) {
        List<Integer> arr = new ArrayList<>();
        postorder(root, arr);

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
        
        List<Integer> result = sol.postOrder(root);

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

