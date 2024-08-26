#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    
    void path(TreeNode* root, string curr, vector<string>& ans) {
        if (!root) return;

      
        curr += to_string(root->val);

      
        if (!root->left && !root->right) {
            ans.push_back(curr);
            return;
        }

        curr += "->";
        path(root->left, curr, ans);
        path(root->right, curr, ans);
    }


    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        path(root, "", v);
        return v;
    }
};


int main() {
    // Constructing the binary tree
    // Let's create the following tree as an example:
    //       1
    //      / \
    //     2   3
    //      \
    //       5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    // Create a Solution object and find all root-to-leaf paths
    Solution sol;
    vector<string> result = sol.binaryTreePaths(root);

    // Output the result
    cout << "All root-to-leaf paths are:" << endl;
    for (const string& path : result) {
        cout << path << endl;
    }

    // Clean up dynamically allocated memory
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
