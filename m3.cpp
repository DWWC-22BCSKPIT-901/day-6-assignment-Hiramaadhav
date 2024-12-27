#include <iostream>
#include <algorithm> // For std::max
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

// Function to find the maximum depth of a binary tree.
int maxDepth(TreeNode* root) {
    if (!root) return 0; // Base case: an empty tree has depth 0.
    // Recursively find the depth of left and right subtrees and add 1 for the current node.
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// Example usage.
int main() {
    // Constructing a binary tree:
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

    // Find the maximum depth of the tree.
    int depth = maxDepth(root);
    cout << "Maximum depth: " << depth << endl;

    // Cleanup.
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
