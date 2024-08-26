#include <iostream>
#include <vector>
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

    bool findPath(TreeNode* root, vector<int>& path, int target) {
        if(!root)return false;

        path.push_back(root->val);

        if(root->val==target){
            return true;
        }

        if(findPath(root->left,path,target) || findPath(root->right,path,target)){
            return true;
        }
        
        path.pop_back();

        return false;


    }

    vector<int> rootToNodePath(TreeNode* root, int target) {
        vector<int> path;
        if (root == nullptr) return path;

        findPath(root, path, target);
        return path;
    }
};

// Main function to demonstrate the usage of Solution and finding the root-to-node path
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

    // Create a Solution object and find the path to the node with value 5
    Solution sol;
    int target = 5;
    vector<int> result = sol.rootToNodePath(root, target);

    // Output the result
    cout << "Path from root to node " << target << " is: ";
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
