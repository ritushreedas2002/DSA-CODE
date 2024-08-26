#include <iostream>
#include <vector>
#include <queue>
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
   
    vector<int> rightView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;

       
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            TreeNode* node;

           
            for (int i = 0; i < levelSize; ++i) {
                node = q.front();
                q.pop();

                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            
            result.push_back(node->val);
        }

        return result;
    }
};

// Main function to demonstrate the usage of BinaryTree and right view calculation
int main() {
    // Constructing the binary tree
    // Let's create the following tree as an example:
    //       1
    //      / \
    //     2   3
    //    / \   \
    //   4   5   6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // Create a BinaryTree object and find the right view of the tree
    BinaryTree tree;
    vector<int> result = tree.rightView(root);

    // Output the result
    cout << "Right view of the tree is: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

   
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
