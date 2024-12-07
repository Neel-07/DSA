#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "X,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> nodes;
        string temp = "";
        for (char c : data) {
            if (c == ',') {
                nodes.push(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        return dfs(nodes);
    }

    TreeNode* dfs(queue<string>& nodes) {
        string val = nodes.front();
        nodes.pop();
        if (val == "X") return NULL;
        TreeNode* node = new TreeNode(stoi(val));
        node->left = dfs(nodes);
        node->right = dfs(nodes);
        return node;
    }
};

int main() {
    Codec codec;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string serialized = codec.serialize(root);
    cout << "Serialized: " << serialized << endl;

    TreeNode* deserialized = codec.deserialize(serialized);
    // You can verify the deserialized tree here
    return 0;
}