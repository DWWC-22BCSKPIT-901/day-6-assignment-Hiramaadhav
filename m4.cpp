#include <iostream>
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

// Function to calculate the sum of all nodes in the binary tree.
int sumOfNodes(TreeNode* root) {
    if (!root) return 0; // Base case: if the tree is empty, return 0.
    // Sum up the current node's value and the values of its left and right subtrees.
    return root->val + sumOfNodes(root->left) + sumOfNodes(root->right);
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

    // Calculate the sum of all nodes.
    int totalSum = sumOfNodes(root);
    cout << "Sum of all nodes: " << totalSum << endl;

    // Cleanup.
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
