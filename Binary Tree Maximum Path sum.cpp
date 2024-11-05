#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxGain(root, maxSum);
        return maxSum;
    }

private:
    // Helper function to calculate maximum gain from each node
    int maxGain(TreeNode* node, int& maxSum) {
        if (!node) return 0;

        // Recursively get the maximum sum of paths in left and right subtrees
        int leftGain = max(maxGain(node->left, maxSum), 0);
        int rightGain = max(maxGain(node->right, maxSum), 0);

        // Current path sum including the current node
        int currentPathSum = node->val + leftGain + rightGain;

        // Update maxSum with the best path found so far
        maxSum = max(maxSum, currentPathSum);

        // Return the maximum gain from either subtree, along with the current node
        return node->val + max(leftGain, rightGain);
    }
};

int main() {
    // Construct binary tree
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    cout << "Maximum Path Sum: " << solution.maxPathSum(root) << endl;

    return 0;
}

