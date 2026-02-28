// Binary Tree Representation in Java

import java.util.*;

class Node {
    int data;
    Node left;
    Node right;

    public Node(int key) {
        data = key;
        left = null;
        right = null;
    }
}


class Solution {
    public Node createBinaryTree() {
        Node root = new Node(1);

        root.left = new Node(2);

        root.right = new Node(3);

        root.right.left = new Node(4);
        
        return root;
    }
}

public class Main {
    public static void main(string[] args) {
        Solution sol = new Solution();

        Node root = sol.createBinaryTree();

        // tree created. it can be used for other operatio s
    }
}