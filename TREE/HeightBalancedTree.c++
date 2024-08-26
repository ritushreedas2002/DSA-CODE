#include <iostream>
#include <algorithm> // For std::max
using namespace std;

// Definition for a binary tree node.
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Helper function to calculate height and check if the tree is balanced
    int checkHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0; // Base case: height of an empty tree is 0
        }

        int leftHeight = checkHeight(root->left);
        if (leftHeight == -1) return -1; // Left subtree is not balanced

        int rightHeight = checkHeight(root->right);
        if (rightHeight == -1) return -1; // Right subtree is not balanced

        // Check the balance condition for the current node
        if (abs(leftHeight - rightHeight) > 1) {
            return -1; // Current subtree is not balanced
        }

        // Return the height of the current node
        return max(leftHeight, rightHeight) + 1;
    }

    // Main function to check if the binary tree is height-balanced
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};

// Main function to demonstrate the usage of Solution and checking if the tree is height-balanced
int main() {
    // Constructing the binary tree
    // Let's create the following tree as an example:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    //  /
    // 6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->left->left = new TreeNode(6);

    // Create a Solution object and check if the tree is height-balanced
    Solution sol;
    bool isBal = sol.isBalanced(root);

    // Output the result
    if (isBal) {
        cout << "The tree is height-balanced." << endl;
    } else {
        cout << "The tree is not height-balanced." << endl;
    }

    // Clean up dynamically allocated memory
    delete root->left->left->left;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
