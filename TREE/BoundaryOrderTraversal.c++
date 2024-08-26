#include <iostream>
#include <vector>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:

    void allleft(Node* root, vector<int>& ans) {
        // Traverse the left boundary without including leaf nodes
        while (root) {
            if (root->left || root->right) {
                ans.push_back(root->data);
            }
            if (root->left) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
    }

    //(consider doining inorder traversal and checking if the node is leaf node or not)
    void leaf(Node* root, vector<int>& ans) {
        // Base case
        if (!root) return;

        // Check if it's a leaf node
        if (!root->left && !root->right) {
            ans.push_back(root->data);
            return;
        }
        // Recursively traverse left and right subtrees
        leaf(root->left, ans);
        leaf(root->right, ans);
    }

   
    void allright(Node* root, vector<int>& ans) {
        vector<int> temp;
        // Traverse the right boundary without including leaf nodes
        while (root) {
            if (root->left || root->right) {
                temp.push_back(root->data);
            }
            if (root->right) {
                root = root->right;
            } else {//if right not present then go to left
                root = root->left;
            }
        }

        // Add right boundary nodes in reverse order to result (as we need to maintain the anticlockwise order)
        for (int i = temp.size() - 1; i >= 0; i--) {
            ans.push_back(temp[i]);
        }
    }

    vector<int> boundary(Node* root) {
        vector<int> ans;
        if (!root) {
            return ans;
        }

        // Include root data if it's not a leaf node
        ans.push_back(root->data);

  
        allleft(root->left, ans);
        leaf(root, ans);
        allright(root->right, ans);

        return ans;
    }
};

// Main function to demonstrate the usage of Solution and boundary traversal
int main() {
    // Constructing the binary tree
    // Let's create the following tree as an example:
    //       1
    //      / \
    //     2   3
    //    / \   \
    //   4   5   6
    //      / \   
    //     7   8
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(8);

    // Create a Solution object and find the boundary of the tree
    Solution sol;
    vector<int> result = sol.boundary(root);

    // Output the result
    cout << "Boundary traversal of the tree is: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up dynamically allocated memory
    delete root->left->right->left;
    delete root->left->right->right;
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
