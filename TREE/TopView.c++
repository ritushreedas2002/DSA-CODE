#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Definition for a binary tree node.
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class BinaryTree {
public:
   
    vector<int> topView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;

        
        map<int, int> topNodes; //<verticallineno,nodevalue>
        
        queue<pair<TreeNode*, int>> q;  //<node,lineno>

        // Start BFS with the root node at horizontal distance 0
        q.push({root, 0});

        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int hd = p.second;

            // If this horizontal distance is not already present in the map, add it
            if (topNodes.find(hd) == topNodes.end()) {
                topNodes[hd] = node->val;
            }

            // Push left and right children with updated horizontal distances
            if (node->left) {
                q.push({node->left, hd - 1});
            }
            if (node->right) {
                q.push({node->right, hd + 1});
            }
        }

        // Extract the top view from the map
        for (auto it : topNodes) {
            result.push_back(it.second);
        }

        return result;
    }
};

// Main function to demonstrate the usage of BinaryTree and top view calculation
int main() {
    // Constructing the binary tree
    // Let's create the following tree as an example:
    //       1
    //      / \
    //     2   3
    //    / \   \
    //   4   5   7
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(7);

    // Create a BinaryTree object and find the top view of the tree
    BinaryTree tree;
    vector<int> result = tree.topView(root);

    // Output the result
    cout << "Top view of the tree is: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up dynamically allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
