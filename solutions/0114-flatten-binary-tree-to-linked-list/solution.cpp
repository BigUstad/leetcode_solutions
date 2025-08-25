/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void iterativePreOrderHelper(TreeNode* root) {
        // dummy node.
        TreeNode* dummy_node = new TreeNode();
        TreeNode* cur = dummy_node;
        std::stack<TreeNode*> s;
        // Pre-Order traversal with stack.
        // It is Root-> Left -> Right
        while (root) {
            // Root processing
            {
                cur->right = root;
                cur->left = nullptr;
                cur = root;
            }
            // Right first because, to put left on top
            if (root->right) {
                s.push(root->right);
            }
            // Left gets dealt with first
            if (root->left) {
                root = root->left;
            } else {
                if (!s.empty()) {
                    root = s.top();
                    s.pop();
                } else {
                    root = nullptr;
                }
            }
        }
        // Last Node.
        if (cur) cur->right = nullptr;
    }
    void flatten(TreeNode* root) {
        // Return for empty tree or a single node tree.
        if (!root || (!root->left && !root->right)) {
            return;
        }

        iterativePreOrderHelper(root);
    }
};
