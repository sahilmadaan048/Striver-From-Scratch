// https://takeuforward.org/while-loop/while-loops-in-programming/

// https://www.geeksforgeeks.org/problems/while-loop-printtable-java/1

import java.util.*;

public class Main {
    public static void main(String args[]) {
        // Your Code Here
                 Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int i = 10; 

        while (i > 0)
        {
            System.out.print(n * i + " ");
            i--; 
        }

        scan.close(); 
    }
}