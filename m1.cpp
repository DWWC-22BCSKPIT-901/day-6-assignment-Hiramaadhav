#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Helper function for recursive inorder traversal.
void inorderHelper(TreeNode* root, vector<int>& result) {
    if (root == nullptr) return;  // Base case: if the node is null, return.
    inorderHelper(root->left, result);  // Visit left subtree.
    result.push_back(root->val);       // Visit current node.
    inorderHelper(root->right, result); // Visit right subtree.
}

// Function to perform inorder traversal.
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    inorderHelper(root, result);
    return result;
}

// Example usage.
int main() {
    // Constructing a simple binary tree:
    //       1
    //        \
    //         2
    //        /
    //       3
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    // Perform inorder traversal.
    vector<int> result = inorderTraversal(root);

    // Print the result.
    for (int val : result) {
        cout << val << " ";
    }

    // Cleanup.
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
