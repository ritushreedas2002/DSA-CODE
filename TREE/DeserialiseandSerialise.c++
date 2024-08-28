#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if (!root) return s;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node) {
                s += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                s += "#,";
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        stringstream s(data);
        string str;
        getline(s, str, ',');
        
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (!curr) continue;  // Skip null nodes

            if (getline(s, str, ',')) {
                if (str != "#") {
                    curr->left = new TreeNode(stoi(str));
                    q.push(curr->left);
                } else {
                    q.push(nullptr);
                }
            }

            if (getline(s, str, ',')) {
                if (str != "#") {
                    curr->right = new TreeNode(stoi(str));
                    q.push(curr->right);
                } else {
                    q.push(nullptr);
                }
            }
        }

        return root;
    }
};