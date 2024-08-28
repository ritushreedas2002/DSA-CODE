#include <iostream>
#include <climits> // For INT_MIN and INT_MAX
using namespace std;


class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    
    bool isValidBST(TreeNode* node, long minVal, long maxVal) {
        if (node == nullptr) return true; 

        if (node->val <= minVal || node->val >= maxVal) return false;

        return isValidBST(node->left, minVal, node->val) && 
               isValidBST(node->right, node->val, maxVal);
    }

  
    bool isValidBST(TreeNode* root) {
        // Use long to avoid integer overflow/underflow issues
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
};

// Main function to demonstrate the usage of Solution and validating BST
int main() {
    // Constructing the binary tree
    // Let's create the following tree as an example:
    //       5
    //      / \
    //     3   7
    //    / \   \
    //   2   4   8
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(8);

    // Create a Solution object and check if the tree is a valid BST
    Solution sol;
    bool isValid = sol.isValidBST(root);

    // Output the result
    if (isValid) {
        cout << "The tree is a valid BST." << endl;
    } else {
        cout << "The tree is not a valid BST." << endl;
    }

    // Clean up dynamically allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
