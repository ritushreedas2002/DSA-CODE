/*Problem: Diameter of Binary Tree
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.*/



#include <iostream>
#include <algorithm> // For the max function
using namespace std;

// Class definition for a binary tree node.
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Class definition for BinaryTree, which includes methods to calculate max depth and diameter.
class BinaryTree {
private:
    int maxDiameter; 
   
    int calculateHeightAndUpdateDiameter(TreeNode* node) {
        if (!node) return 0; // Base case: empty node has height 0

        // Recursively get the height of the left and right subtrees
        int leftHeight = calculateHeightAndUpdateDiameter(node->left);
        int rightHeight = calculateHeightAndUpdateDiameter(node->right);

        // Update the maximum diameter: it could be the sum of left and right subtree heights
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);

        // Return the height of the current node
        return max(leftHeight, rightHeight) + 1;
    }

public:
    BinaryTree() : maxDiameter(0) {} // Constructor initializes maxDiameter

    
    int diameterOfBinaryTree(TreeNode* root) {
        maxDiameter = 0; // Reset the max diameter
        calculateHeightAndUpdateDiameter(root); // Update max diameter during the height calculation
        return maxDiameter;
    }
};

int main() {
    // Constructing the binary tree
    // Let's create the following tree as an example:
    //       1
    //      / \
    //     2   3
    //    / \    
    //   4   5  
    //      /
    //     6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);

    // Create a BinaryTree object and find the diameter of the tree
    BinaryTree tree;
    int diameter = tree.diameterOfBinaryTree(root);

    // Output the result
    cout << "The diameter of the tree is: " << diameter << endl;

    // Clean up dynamically allocated memory
    delete root->left->right->left;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
