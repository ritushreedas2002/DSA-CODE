#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        
        queue<TreeNode*> q1;
        bool flagRev = false; 

        q1.push(root);

        while (!q1.empty()) {
            int size = q1.size();
            vector<int> lvl;

            for (int i = 0; i < size; ++i) {
                TreeNode* curr = q1.front();
                q1.pop();

                if (curr->left) q1.push(curr->left);
                if (curr->right) q1.push(curr->right);

             
                lvl.push_back(curr->val);
            }

          
            if (flagRev) {
                reverse(begin(lvl), end(lvl));
            }
            flagRev = !flagRev;
            res.push_back(lvl);
        }

        return res;
    }
};


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

    // Create a BinaryTree object and perform zigzag level order traversal
    BinaryTree tree;
    vector<vector<int>> result = tree.zigzagLevelOrder(root);

    // Output the result
    cout << "Zigzag level order traversal of the tree is: " << endl;
    for (const vector<int>& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
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
