#include <iostream>
#include <vector>
#include <map>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Map to store the index of each value in inorder
        map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }

        // Call the recursive function with the initial indices
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorderMap);
    }

private:
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int>& inorderMap) {
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }

        // The first element of the preorder is the root of the current subtree
        TreeNode* root = new TreeNode(preorder[preStart]);

        // Find the root in inorder list to split into left and right subtrees
        int rootIndex = inorderMap[root->val];
        int leftTreeSize = rootIndex - inStart;

        // Recursively construct the left and right subtrees
        root->left = buildTree(preorder, preStart + 1, preStart + leftTreeSize, inorder, inStart, rootIndex - 1, inorderMap);
        root->right = buildTree(preorder, preStart + leftTreeSize + 1, preEnd, inorder, rootIndex + 1, inEnd, inorderMap);

        return root;
    }
};

// Function to print the tree in inorder (used for testing)
void printInorder(TreeNode* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Main function to demonstrate the usage of Solution and building the tree
int main() {
    Solution sol;
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode* root = sol.buildTree(preorder, inorder);

    // Output the tree using inorder traversal to verify the structure
    cout << "Inorder traversal of the constructed tree: ";
    printInorder(root);
    cout << endl;

    // Remember to free the allocated memory after use
    // (A function to delete the tree would be needed here to avoid memory leaks)

    return 0;
}
