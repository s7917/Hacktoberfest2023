//Find the diagonal sum of a binary tree
import java.util.HashMap;
import java.util.Map;
 
// A class to store a binary tree node
class Node
{
    int data;
    Node left = null, right = null;
 
    Node(int data) {
        this.data = data;
    }
}
 
class Main
{
    // Recursive function to perform preorder traversal on the tree and
    // fill the map with the diagonal sum of elements
    public static void diagonalSum(Node root, int diagonal, Map<Integer, Integer> map)
    {
        // base case: empty tree
        if (root == null) {
            return;
        }
 
        // update the current diagonal with the node's value
        map.put(diagonal, map.getOrDefault(diagonal, 0) + root.data);
 
        // recur for the left subtree by increasing diagonal by 1
        diagonalSum(root.left, diagonal + 1, map);
 
        // recur for the right subtree with the same diagonal
        diagonalSum(root.right, diagonal, map);
    }
 
    // Function to print the diagonal sum of a given binary tree
    public static void diagonalSum(Node root)
    {
        // create an empty map to store the diagonal sum for every slope
        Map<Integer, Integer> map = new HashMap<>();
 
        // traverse the tree in a preorder fashion and fill the map
        diagonalSum(root, 0, map);
 
        // traverse the map and print the diagonal sum
        System.out.println(map.values());
    }
 
    public static void main(String[] args)
    {
        /* Construct the following tree
                   1
                 /   \
                /     \
               2       3
              /      /  \
             /      /    \
            4      5      6
                  / \
                 /   \
                7     8
        */
 
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.right.left = new Node(5);
        root.right.right = new Node(6);
        root.right.left.left = new Node(7);
        root.right.left.right = new Node(8);
 
        diagonalSum(root);
    }
}
