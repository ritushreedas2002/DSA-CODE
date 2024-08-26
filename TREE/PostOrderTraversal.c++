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
   
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;

        stack<TreeNode*> stk1, stk2;
        stk1.push(root);

        while (!stk1.empty()) {
            TreeNode* node = stk1.top();
            stk1.pop();
            stk2.push(node);

            
            if (node->left) {
                stk1.push(node->left);
            }
            if (node->right) {
                stk1.push(node->right);
            }
        }

       
        while (!stk2.empty()) {
            result.push_back(stk2.top()->val);
            stk2.pop();
        }

        return result;
    }
};

// Main function to demonstrate the usage of BinaryTree and postorder traversal
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

    // Create a BinaryTree object and perform postorder traversal
    BinaryTree tree;
    vector<int> result = tree.postorderTraversal(root);

    // Output the result
    cout << "Postorder traversal of the tree is: ";
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
