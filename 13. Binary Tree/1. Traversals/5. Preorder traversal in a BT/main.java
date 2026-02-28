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
    public void preorder(Node root, List<Integer> arr) {
        if(root == null) {
            return;
        }

        arr.add(root.data);

        preorder(root.left, arr);
        preorder(root.right, arr);
    }

    public List<Integer> preOrder(Node root) {
        List<Integer> arr = new ArrayList<>();
        preorder(root, arr);

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
    
        Solutoin sol = new Solution();
        
        List<Integer> result = sol.preOrder(root);

        System.out.println("Preorder Traversal: ");

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

