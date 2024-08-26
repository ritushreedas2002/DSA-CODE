#include <iostream>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: if the current node is NULL, or p, or q, return it
        if (root == NULL || root == p || root == q) {
            return root;
        }

        // Recursively search the left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both left and right are not NULL, it means p and q are found in different branches
        // Thus, the current node is the LCA
        if (left != NULL && right != NULL) {
            return root;
        }

        // If only one of them is non-null, return the non-null one (either left or right)
        return (left != NULL) ? left : right;
    }
};

// Main function to demonstrate the usage of Solution and finding LCA
int main() {
    // Constructing the binary tree
    // Let's create the following tree as an example:
    //       3
    //      / \
    //     5   1
    //    / \ / \
    //   6  2 0  8
    //     / \
    //    7   4
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // Nodes to find LCA for
    TreeNode* p = root->left; // Node with value 5
    TreeNode* q = root->left->right->right; // Node with value 4

    // Create a Solution object and find the LCA
    Solution sol;
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);

    // Output the result
    if (lca) {
        cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    } else {
        cout << "No common ancestor found." << endl;
    }

    // Clean up dynamically allocated memory
    delete root->left->right->left;
    delete root->left->right->right;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
