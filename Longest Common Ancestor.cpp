#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Recursive function to find LCA
TreeNode* findLCA(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;

    TreeNode* left = findLCA(root->left, p, q);
    TreeNode* right = findLCA(root->right, p, q);

    if (left && right) return root;
    return left ? left : right;
}

int main() {
    // Create a simple tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* p = root->left;     // Node with value 5
    TreeNode* q = root->left->right->right;  // Node with value 4

    TreeNode* lca = findLCA(root, p, q);

    if (lca) {
        cout << "LCA of " << p->val << " and " << q->val << " is " << lca->val << endl;
    } else {
        cout << "LCA not found" << endl;
    }

    return 0;
}
