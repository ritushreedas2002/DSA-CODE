#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Class for BinaryTree operations, including iterative preorder traversal.
class BinaryTree {
public:
    // Method to perform iterative preorder traversal
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;

        stack<TreeNode*> stk;
        stk.push(root);

        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
            result.push_back(node->val); // Visit the node

            // Push right child first so that left child is processed first
            if (node->right) {
                stk.push(node->right);
            }
            if (node->left) {
                stk.push(node->left);
            }
        }

        return result;
    }
};

// Main function to demonstrate the usage of BinaryTree and preorder traversal
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

    // Create a BinaryTree object and perform preorder traversal
    BinaryTree tree;
    vector<int> result = tree.preorderTraversal(root);

    // Output the result
    cout << "Preorder traversal of the tree is: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up dynamically allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
