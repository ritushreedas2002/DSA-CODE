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


class BinaryTree {
public:
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stk;
        TreeNode* current = root;

        while (current != nullptr || !stk.empty()) {
            // Reach the leftmost node of the current node
            while (current != nullptr) {
                stk.push(current);
                current = current->left;
            }

           
            current = stk.top();
            stk.pop();
            result.push_back(current->val); // Visit the node

            // Visit the right subtree
            current = current->right;
        }

        return result;
    }
};

// Main function to demonstrate the usage of BinaryTree and inorder traversal
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

    // Create a BinaryTree object and perform inorder traversal
    BinaryTree tree;
    vector<int> result = tree.inorderTraversal(root);

    // Output the result
    cout << "Inorder traversal of the tree is: ";
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
