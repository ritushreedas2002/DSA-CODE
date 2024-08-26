#include <iostream>
#include <algorithm> 
using namespace std;


class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class BinaryTree {
public:
    // Method to calculate the maximum depth of the binary tree.
    int maxDepth(TreeNode* root) {
        if (!root) return 0; 
        if (!root->left && !root->right) return 1; 
        int leftDepth = maxDepth(root->left); 
        int rightDepth = maxDepth(root->right); 
        return max(leftDepth, rightDepth) + 1;
    }
};

// Main function to demonstrate the usage of the BinaryTree class and maxDepth method.
int main() {
    // Constructing the binary tree
    // Let's create the following tree as an example:
    //       1
    //      / \
    //     2   3
    //    / \    
    //   4   5  
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Create a BinaryTree object and find the maximum depth of the tree
    BinaryTree tree;
    int depth = tree.maxDepth(root);

    // Output the result
    cout << "The maximum depth of the tree is: " << depth << endl;

    // Clean up dynamically allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
