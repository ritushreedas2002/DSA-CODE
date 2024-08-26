#include <iostream>
#include <vector>
#include <map>
#include <set>
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
 
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;

        
        map<int, map<int, multiset<int>>> nodes; // <vertical, <level, nodes>>
     
        queue<pair<TreeNode*, pair<int, int>>> q; //node,vertical,level

       
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int hd = p.second.first;
            int level = p.second.second;

            nodes[hd][level].insert(node->val);

            if (node->left) {
                q.push({node->left, {hd - 1, level + 1}});
            }
            if (node->right) {
                q.push({node->right, {hd + 1, level + 1}});
            }
        }

        // Extract the vertical order traversal from the map
        for (auto& p : nodes) {
            vector<int> col;
            for (auto& q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            result.push_back(col);
        }

        return result;
    }
};

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

    
    BinaryTree tree;
    vector<vector<int>> result = tree.verticalTraversal(root);

    
    cout << "Vertical order traversal of the tree is: " << endl;
    for (const vector<int>& col : result) {
        for (int val : col) {
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
