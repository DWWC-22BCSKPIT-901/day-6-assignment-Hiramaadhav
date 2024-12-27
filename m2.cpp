#include <iostream>
#include <cmath>
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

// Helper function to calculate the height of the leftmost branch.
int leftHeight(TreeNode* node) {
    int height = 0;
    while (node) {
        height++;
        node = node->left;
    }
    return height;
}

// Helper function to calculate the height of the rightmost branch.
int rightHeight(TreeNode* node) {
    int height = 0;
    while (node) {
        height++;
        node = node->right;
    }
    return height;
}

// Function to count nodes in a complete binary tree.
int countNodes(TreeNode* root) {
    if (!root) return 0; // Base case: empty tree has 0 nodes.

    int lh = leftHeight(root);
    int rh = rightHeight(root);

    if (lh == rh) {
        // Perfect binary tree case: Total nodes = 2^h - 1.
        return (1 << lh) - 1;
    } else {
        // Recursively count nodes in left and right subtrees.
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

// Example usage.
int main() {
    // Constructing a complete binary tree:
    //       1
    //      / \
    //     2   3
    //    / \  /
    //   4  5 6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    // Count the nodes.
    int result = countNodes(root);
    cout << "Number of nodes: " << result << endl;

    // Cleanup.
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
