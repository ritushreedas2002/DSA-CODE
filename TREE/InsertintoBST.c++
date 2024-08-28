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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) return new TreeNode(val); // If tree is empty, create a new node as the root

        TreeNode* curr = root;
        while (true) {
            // Insert into the right subtree
            if (curr->val <= val) {
                if (curr->right) {
                    curr = curr->right;
                } else {
                    TreeNode* newNode = new TreeNode(val);
                    curr->right = newNode;
                    break;
                }
            }
            // Insert into the left subtree
            else {
                if (curr->left) {
                    curr = curr->left;
                } else {
                    TreeNode* newNode = new TreeNode(val);
                    curr->left = newNode;
                    break;
                }
            }
        }
        return root; // Return the unchanged root node
    }
};

// Helper function to print the tree in inorder (for validation)
void printInorder(TreeNode* node) {
    if (node == nullptr) return;
    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

// Main function to demonstrate the usage of Solution and inserting into a BST
int main() {
    // Create an example BST
    //       4
    //      / \
    //     2   7
    //    / \
    //   1   3
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution sol;
    int valToInsert = 5;

    // Insert value into the BST
    root = sol.insertIntoBST(root, valToInsert);

    // Print inorder traversal of the updated tree (should show the BST property)
    cout << "Inorder traversal of the updated BST: ";
    printInorder(root);
    cout << endl;

    // Clean up dynamically allocated memory (a function to delete the tree would be needed here)

    return 0;
}
