#include <iostream>
#include <vector>
#include <unordered_map>
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
    // Helper function to build the tree using postorder and inorder traversals
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inorderStart, int inorderEnd, int& postorderIndex, unordered_map<int, int>& inorderMap) {
        // Base case
        if (inorderStart > inorderEnd) {
            return nullptr;
        }

        // The current root's value is the current element in postorder traversal
        int rootVal = postorder[postorderIndex];
        TreeNode* root = new TreeNode(rootVal);

        // Decrease postorder index
        postorderIndex--;

        // Root splits inorder list into left and right subtrees
        int rootIndex = inorderMap[rootVal];

        // Build the right subtree first because the current postorderIndex represents the last element of postorder array, which is the root of right subtree.
        root->right = buildTreeHelper(inorder, postorder, rootIndex + 1, inorderEnd, postorderIndex, inorderMap);

        // Build the left subtree
        root->left = buildTreeHelper(inorder, postorder, inorderStart, rootIndex - 1, postorderIndex, inorderMap);

        return root;
    }

    // Main function to construct a binary tree from inorder and postorder traversal
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Create a map to store the index of each value in inorder traversal for quick access
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }

        int postorderIndex = postorder.size() - 1; // Start from the last index of postorder traversal
        return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1, postorderIndex, inorderMap);
    }
};

// Helper function to print the tree in inorder (for validation)
void printInorder(TreeNode* node) {
    if (node == nullptr) return;
    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

// Main function to demonstrate the usage of Solution and building the tree
int main() {
    Solution sol;
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    TreeNode* root = sol.buildTree(inorder, postorder);

    // Print inorder traversal of the constructed tree (should match the original inorder input)
    cout << "Inorder traversal of the constructed tree: ";
    printInorder(root);
    cout << endl;

    // Remember to clean up allocated memory (a function to delete the tree would be needed here)

    return 0;
}
